/*
jQuery( function($) {
	
	$(document).ready(function(){
		$(".paragraphs-items").insertBefore("#main");
		
		});

	
});*/
(function($) {
    Drupal.behaviors.edu_custom = {
        attach: function(context, settings) {
          	$(document).ready(function(){
		$(".paragraphs-items-field-header-slideshow").insertBefore("#main");
		var url=$(".views-field-field-mp4-video .field-content").text();
		$(".views-field-field-mp4-video").each(function()
		{var url = $(this).children('div').text();
    $(this).children('div').after('<video aria-hidden="true" autoplay="autoplay" muted="muted" src="' + url+ '" style="width: 100%;"> </video>');
  		
  		
		//};)
		//$(".views-field-field-mp4-video .field-content").after('<video aria-hidden="true" autoplay="autoplay" muted="muted" src="' + url+ '" style="width: 100%;"> </video>');
		})
		});
          
          
                 }
    };
})(jQuery);