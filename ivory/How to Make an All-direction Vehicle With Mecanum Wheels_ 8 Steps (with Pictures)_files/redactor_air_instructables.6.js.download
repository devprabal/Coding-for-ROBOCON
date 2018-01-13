

function loadRedactorAir($elements,options){
    // we can increment the script manually here, or pass in a build hash where it's available.
    var salt = "20140122C";
    if (typeof options !== "undefined" && typeof options.hash !== "undefined") {
        salt = options.hash;
    }
    head.load(
        '/static/drag_editor/dependencies/redactorInstructables/redactorInstructables.3.js?v='+salt,
        '/static/drag_editor/dependencies/redactor916/redactor/redactor.min.js?v='+salt,
        function(){
            // loading CSS reportedly works, but makes the callback inconsistent. Let's put that where it doesn't matter.
            // ie9 doesn't support loading multiple css sheets in one call. separate into multiple calls for compatibility
            // see http://stackoverflow.com/questions/17551294/head-js-only-loads-the-first-stylesheet-in-ie9-and-under
            head.load('/static/drag_editor/dependencies/redactor916/redactor/redactor.css?v='+salt)
                .load('/static/drag_editor/dependencies/redactorInstructables/airmode_styles.css?v='+salt);
            var redactorOptions = {
                air:true,
                plugins: ['instructables','instructablesAir'],
                airButtons: ['bold', 'italic', 'heading', 'link_ibles', 'quote'],
                convertVideoLinks: true,
                convertLinks: true,
                buttonsCustom: {
                    link_ibles: {
                        title: 'Link',
                        callback: function(e){this.ibles_makeLink(e);}
                    },
                    heading: {
                        title: 'Heading',
                        callback: function(e){this.ibles_makeheader(e);}
                    },
                    quote: {
                        title: 'Blockquote',
                        func:'formatQuote'
                    }
                }
            };
            if (typeof options !== "undefined" && typeof options.redactorOptions !== "undefined") {
                $.extend(redactorOptions,options.redactorOptions);
            }

            $elements.redactor(redactorOptions);
            if (typeof options !== "undefined" && typeof options.callback === "function") {
                options.callback();
            }
        }
    );
}
