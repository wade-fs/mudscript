//排版與補充顏色結尾與協助塑造立體的視覺 by blazakira 2011/10/19

#include <room.h>
inherit ROOM;

void create()
{
  set("short", "仙劍派大門");
  set("long", @LONG
                                                            
                                                               
         ╭╯   ║         ╭╮       ║       ╭╯╭          
       ╭╯     ║       ╭╯╰╮     ║   ╮  ╯╭╯          
     ╭╯║     ║     ╭╯══╰╮║ ║   ╰                  
         ║     ║       ─╖ ─╖ ║ ║   ╮ ║ ║            
         ║     ║      ║ ║║ ║    ║   ╰ ║ ║ ╮ ●      
         ║ ║  ║  ║  ╙─ ╙─     ║      ║ ║ ╰╮       
         ║ ╰═╩═╯  ╭ ╮╭ ╮    ║   ╭ ║ ║   ╰╮     
                                      ╯   ╯ ╯ ╯         ▕
  ▕   ▕                                              ▕   ▕
  ▕   ▕                                              ▕   ▕
  ▕   ▕                                              ▕   ▕
  ▕   ▕                                              ▕   ▕
  ▕   ▕                                              ▕   ▕
  ▕   ▕                                              ▕   ▕
  ▕   ▕                                              ▕   ▕
  ▕                                                   ▕   
LONG
  );

  set("exits", ([
    "enter":__DIR__"g1-1",
    "down":__DIR__"road8",
  ]) );
  set("light_up",1);
  setup();
}
