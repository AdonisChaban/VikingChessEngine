#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

int main(){
  int redraw = 1;
  ALLEGRO_EVENT event;
  
  // Initialization of addons
  if(!al_init()){
    printf("couldn't initialize allegro\n");
    return 1;
  }

  if(!al_install_mouse()){
    printf("could't initialize mouse driver\n");
    return 1;
  }

  if(!al_init_primitives_addon()){
    printf("primitive addon didn't init\n");
    return 1;
  }
  
  // initialization addons done

  ALLEGRO_DISPLAY* window = al_create_display(450, 450);
  if(!window){
    printf("couldn't create display\n");
    return 1;
  }

  ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
  if(!event_queue){
    printf("couldn't establish the event queue\n");
    return 1;
  }

  al_register_event_source(event_queue, al_get_display_event_source(window));

  al_clear_to_color(al_map_rgb(245, 222, 179));

  // drawing the background
  for(int x = 0; x < 9; x++){
    for(int y = 0; y < 9; y++){
      al_draw_rectangle(x * 50, y *50, (x + 1) * 50, (y + 1) * 50, al_map_rgb(0, 0, 0), 1);
    }
  }

  al_draw_filled_circle(225,225, 15, al_map_rgb(0,0,0));
  
  al_flip_display();
  

  while(1){
    al_wait_for_event(event_queue, &event);
    
  
    if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
      break; 
    }
      
  }


  // Destroy
  al_destroy_display(window);
  al_destroy_event_queue(event_queue);
  al_shutdown_primitives_addon();
  
  
  return 0;
}
