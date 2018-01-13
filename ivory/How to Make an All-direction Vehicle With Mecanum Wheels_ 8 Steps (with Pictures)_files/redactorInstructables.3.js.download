if (typeof RedactorPlugins === 'undefined') var RedactorPlugins = {};

RedactorPlugins.instructables = {
    init: function() {
        var that = this;
        this.opts.enterCallback = function(e) {
            $.proxy(that.endBlockQuote(e),that);
        };
    },

    endBlockQuote: function(e){
        if (this.getBlock() && $(this.getBlock()).get(0).tagName === 'BLOCKQUOTE') {
            // Cursor is in a block quote. If there's been a blank line lately, exit
            var quoteContents = $(this.getBlock()).html();
            if (quoteContents.charCodeAt(quoteContents.length-1)) {
                // line ends in an empty character. preceding that, br? If so, exit blockquote.
                if (quoteContents.slice(-5,-1) === "<br>" && quoteContents.slice(-10,-6) === "<br>") {
                    var html = $(this.getBlock()).html();
                    html = html.slice(0,html.length-10);
                    $(this.getBlock()).remove();
                    this.insertHtmlAdvanced("<blockquote>"+html+"</blockquote>");
                    this.sync();
                    this.insertAfterLastElement(this.getBlock());
                }
            }
        }
    },
    //overriding existing redactor function
    execCommand: function(cmd, param, sync)
    {
        if (!this.opts.visual)
        {
            this.$source.focus();
            return false;
        }

        if (cmd === 'inserthtml')
        {
            this.insertHtml(param, sync);
            this.callback('execCommand', cmd, param);
            return;
        }

        // stop formatting pre
        if (this.currentOrParentIs('PRE') && !this.opts.formattingPre)
        {
            return false;
        }

        if (cmd === 'insertunorderedlist' || cmd === 'insertorderedlist')
        {
            this.bufferSet();

            var parent = this.getParent();
            var $list = $(parent).closest('ol, ul');
            var remove = false;

            if ($list.length)
            {
                remove = true;
                var listTag = $list[0].tagName;
                if ((cmd === 'insertunorderedlist' && listTag === 'OL')
                    || (cmd === 'insertorderedlist' && listTag === 'UL'))
                {
                    remove = false;
                }
            }
            this.selectionSave();
            //strip list formatting
            if (remove)
            {
                var nodes = this.getNodes(),
                    elems = this.getBlocks(nodes),
                    selectionStarted = false;

                if (typeof nodes[0] != 'undefined' && nodes.length > 1 && nodes[0].nodeType == 3)
                {
                    // fix the adding the first li to the array
                    elems.unshift(this.getBlock());
                }
                var data = '', replaced = '';
                $.each(elems, $.proxy(function(i,s){
                    var $s = $(s);
                    if ($s.children('#selection-marker-1').length !== 0) {
                        selectionStarted = true;
                    }
                    if (s.tagName == 'LI' && selectionStarted){
                        var cloned = $s.clone();
                        cloned.find('ul', 'ol').remove();
                        if (this.opts.linebreaks === false) data += this.outerHtml($('<p>').append(cloned.contents()));
                        else data += cloned.html() + '<br>';

                        if ($s.children('#selection-marker-1').length !== 0)
                        {
                            $s.addClass('redactor-replaced').empty();
                            replaced = this.outerHtml($s);
                        }
                        else $s.remove();
                    }

                }, this));

                var closeTags = '', openTags = '';
                var removeParentLists = function(i,parent){
                    var tag = parent.tagName;
                    closeTags = closeTags + '</' + tag + '>';
                    openTags =  '<' + tag + '>' + openTags;
                };

                var removeEmptyTags = $.proxy(function (i,parent){
                    var tag = parent.tagName;
                    this.$editor.find(tag + ':empty').remove();
                },this);

                var parents = $(".redactor-replaced").parents('ol,ul,li');
                $.each(parents, removeParentLists)

                html = this.$editor.html().replace(replaced, closeTags + data + openTags);
                this.$editor.html(html);

                $.each(parents,removeEmptyTags);
            }

            else{
                //change list type
                if ($list.length !== 0){
                    var newTag = $list[0].tagName === 'UL' ? 'OL' : 'UL',
                        listContents = $list.html();
                    $list.addClass('redactor-replaced').empty();
                    var replaced = this.outerHtml($list);
                    html = this.$editor.html().replace(replaced, '<' + newTag + '>' + listContents + '</' + newTag + '>');
                    this.$editor.html(html);
                }
                // insert lists into plaintext
                else{
                    this.document.execCommand(cmd);
                }
            }

            this.selectionRestore();

            this.sync();
            this.callback('execCommand', cmd, param);
            return;
        }

        if (cmd === 'unlink')
        {
            this.bufferSet();

            var link = this.currentOrParentIs('A');
            if (link)
            {
                $(link).replaceWith($(link).text());

                this.sync();
                this.callback('execCommand', cmd, param);
                return;
            }
        }

        this.exec(cmd, param, sync);

        if (cmd === 'inserthorizontalrule')
        {
            this.$editor.find('hr').removeAttr('id');
        }
    }
};

// The use of Instructables' modifications to air mode could disrupt behavior of redactor
// unintentionally when redactor is used in the standard toolbar mode. Thus, two plugins.
RedactorPlugins.instructablesAir = {
    init: function() {
        //allow admins to get out of html edit mode (if it exists) by right clicking!
        this.$source.on('contextmenu', this, $.proxy(function(e)
        {
            this.airShow(e)
        }, this));
    },

    ibles_makeLink: function(){
        // You can click the link button from any clicked link or highlighted text.
        // Figure out first if we're inside a link block. If so, edit. If not, create.
        if (this.getParent() !== false) {
            if (this.getParent().nodeName == "A") {
                this.airLinkMode($(this.getParent()));
                return;
            } else if (typeof $(this.getParent()).parent().get(0) !== "undefined" && $(this.getParent()).parent().get(0).nodeName == "A") {
                // this handles an edge case where someone tries to put a link on already-styled text inside another link
                this.airLinkMode($(this.getParent()).parent());
                return;
            }
        }

        // If it's not already a link, create it one then edit.
        var inputText = this.getSelectionText(),
            resolvedLink = this.resolvedLinkHTML(inputText);

        if (resolvedLink === inputText) {
            resolvedLink = "";
            this.insertHtmlAdvanced('<a href="'+resolvedLink+'">'+inputText+'</a>');
        }
        else{
            this.insertHtmlAdvanced(resolvedLink);
        }

        this.sync();

        // totally custom stuff begins here.
        this.airLinkMode();
    },
    airLinkMode: function($link){
        //firefox returns an element two dom elements above the link with getCurrent, so we need to stay in the editor
        // and get a anchor tag
        if (typeof $link === "undefined") {
            $link = this.getParent() ? $(this.getParent()) : $(this.getCurrent());
        }
        if ($link.prop('tagName') !== 'A'){
            $link = $link.find('a');
        }
        var linkButtons = this.buildLinkButtons($link);
        var tooltip = $('<span class="redactor-link-tooltip"></span>');

        tooltip.append(linkButtons.aLink);
        tooltip.append(' | ');
        tooltip.append(linkButtons.aEdit);
        tooltip.append(' | ');
        tooltip.append(linkButtons.aUnlink);

        this.$air.append(tooltip);

        var that = this,
            commentBox = this.$editor.parents('.post-comment-box');

        commentBox.find('#PostCommentLink').click(function(e) {
            e.preventDefault();
            that.airHide();
        });

        setTimeout(function(){
            that.$air.addClass("linkMode"); // slide buttons out of the way while editing a link
            linkButtons.aLink.focus();
        },10);


    },

    //overriding existing redactor function
    airBindMousemoveHide: function(){
        // we need an empty implementation to disable this feature.
    },
    ibles_makeheader: function(e){
        if (this.getBlock().nodeName == "H4") {
            this.formatBlocks('p');
            this.sync();
        } else {
            // redactor can already apply , it just doesn't have its own button for it
            this.formatBlocks('H4');
            this.sync();
        }
    },

    resolvedLinkHTML: function(text){
        var html = text,
            regex = new RegExp("^(http[s]?:\\/\\/(www\\.)?|ftp:\\/\\/(www\\.)?|www\\.){1}([0-9A-Za-z-\\.@:%_\+~#=]+)+((\\.[a-zA-Z]{2,3})+)(/(.)*)?(\\?(.)*)?"),
            match = text.match(regex);
        if (match !== null) {
            var fullLink = match[0];
            fullLink = this.addProtocolIfNeeded(fullLink);
            html = '<a href="'+fullLink+'" target="_blank">'+text+'</a>';
        }
        return html;
    },
    addProtocolIfNeeded: function(fullLink){
        var testHasProtocol = new RegExp("^(http[s]?:\\/\\/|ftp:\\/\\/){1}");
        if (fullLink.match(testHasProtocol) === null ) {
            fullLink = "http://" + fullLink;
        }
        return fullLink;
    },
    buildLinkButtons: function($link){
        //firefox returns an element two dom elements above the link with getCurrent, so we need to stay in the editor
        // and get a anchor tag
        var $anchorBlock = this.getParent() ? $(this.getParent()) : $(this.getCurrent());
        if ($anchorBlock.prop('tagName') !== 'A'){
            $anchorBlock = $anchorBlock.find('a');
        }
        $anchorBlock.attr('target',"_blank");
        var that = this;

        var href = $link.attr('href');
        if (typeof href === "undefined") {
            href = "";
        }

        var aLink = $("<input type='text' class='redactorair_editLink_custom' placeholder='Paste or Type a Link' value='"+href+"'/>").on('keyup', function(e)
        {
            var currentVal = $(this).val();
            currentVal = that.addProtocolIfNeeded(currentVal);
            $anchorBlock.attr('href',currentVal);
        });

        var aEdit = $('<a href="#">' + 'Test' + '</a>').on('click', $.proxy(function(e)
        {
            e.preventDefault();
            var href = this.addProtocolIfNeeded(aLink.val());
            window.open(href,'_blank');
        }, this));

        var aUnlink = $('<a href="#">' + this.opts.curLang.unlink + '</a>').on('click', $.proxy(function(e)
        {
            e.preventDefault();
            $link.replaceWith($link.text());
            this.airHide();
        }, this));

        return {
            aLink: aLink,
            aEdit: aEdit,
            aUnlink: aUnlink
        }
    },
    //overriding existing redactor function
    observeLinks: function()
    {
        var that = this;
        this.$editor.on('click',"a", $.proxy(that.airShow, that) );
    },
    airHide: function(){
        var that=this;
        setTimeout(function(){
            that.$air.fadeOut(100,function(){
                $(this).find('.redactor-link-tooltip').remove();
                $(this).removeClass("linkMode");
            });
        },10);
        this.blockSetAttr('href', this.$air.find('.redactorair_editLink_custom').val());
        this.sync();
    },
    //overriding existing redactor function
    airBindHide: function()
    {
        if (!this.opts.air) return;

        var hideHandler = $.proxy(function(doc)
        {
            $(doc).on('mousedown',".redactor_editor", $.proxy(function(e)
                {
                    if ($( e.target ).closest(this.$toolbar).length === 0)
                    {
                        this.airHide();
                        this.selectionRemove();
                        $(doc).off(e);
                    }

                }, this)).on('keydown.redactor', $.proxy(function(e)
                {
                    if (e.which === this.keyCode.ESC)
                    {
                        this.getSelection().collapseToStart();
                    }
                    if (!this.$air.hasClass("linkMode")) {
                        // Do not hide air toolbar because of a keydown when editing a link. you need to be able to type!
                        this.airHide();
                        $(doc).off(e);
                    }

                }, this));
        }, this);

        // Hide the toolbar at events in all documents (iframe)
        hideHandler(document);
        if (this.opts.iframe) hideHandler(this.document);
    },
    // SHORTCUTS overrides redactor function of same name. This is so we have our own custom shortcuts.
    shortcuts: function(e, key)
    {
        if (!this.opts.shortcuts) return;

        if (!e.altKey) {
            if (key === 66) {this.shortcutsLoad(e, 'bold');} // Ctrl + b
            else if (key === 73) {this.shortcutsLoad(e, 'italic');} // Ctrl + i
            else if (key === 85) {this.shortcutsLoad(e, 'underline');} // Ctrl + u
            else if (key === 75) {  // Ctrl + k does not have a redactor shortcut that we use
                // select the current word
                var current = this.getCurrent(),
                    selectionBounds = this.getWordBoundsAt($(current).text(),this.getCaretOffset(current));
                this.setCaret($(current), selectionBounds[0],selectionBounds[1]);

                // make it a link and bring up the toolbar
                this.ibles_makeLink();
                this.triggerAirForElement($(this.getBlock()).find('a'));
            }
            else if (key === 77) this.shortcutsLoad(e, 'removeFormat'); // Ctrl + m
        }
    },
    triggerAirForElement: function($el){
        var offset = $el.offset();
        this.$air.css({
            left: offset.left + 'px',
            top: offset.top + 14 + 'px'
        }).addClass("linkMode").show();
        this.airBindHide();
    },
    getWordBoundsAt: function(str, pos) {
        // Perform type conversions.
        str = String(str);
        pos = Number(pos) >>> 0;

        // Search for the word's beginning and end.
        var left = str.slice(0, pos + 1).search(/\S+$/),
            right = str.slice(pos).search(/\s/);

        // The last word in the string is a special case.
        if (right < 0) {
            return str.slice(left);
        }

        // Return the position of the word so it can be selected
        return [left, right + pos];
    }
};

