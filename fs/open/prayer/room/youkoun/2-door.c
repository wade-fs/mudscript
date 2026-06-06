//open/prayer/room/youkoun/2-door.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","大門");
        set("long",@LONG

                ,,;,                ,,              ,;;;;;,,   ,,,,,,,,
            ,,;;;  ';;,          ,  ;'              ;;,,,,;;   ;,,,,,;;
 ,;;;;;;, '';,, ';,,;'       ,,;;'  ;   ;;;,,       ;;'''';;   ;''''';;
     ;       ;;;;''                 ;               ;;,,,,;;   ;,,,,,;;
  ,,,;,,,';;';;,,,,,,,     ,,;;;;;;;;;;;;;;;;;      ;;'''''          ;;
 '''';'''   ,'  ';                ;; ;              ;'               ;;
     ;    ,,,,,;;;';,,,,,       ,;'  ;             ;;                ;;
 ,,,;;;;;   ,,   ;   ,,       ,;'    ;            ,;'                ;;
 ''         ;;  ,;,,,;;   ,,;;'      ';,,,,,,,;;';;'                 ';,
             '''''''''    '''             '''''  ''                   ''

LONG);
     set("item_desc", ([ /* sizeof() == 1 */
      "north" : (: look_door,     "north" :),
]));

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"20",            //練武場
        "east":"/open/prayer/room/westarea/road34",     //馬路
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/door-looker1" : 2,            //大門守衛 
                
]));
        set("light_up", 1);
        create_door("north","聖火刻紋精鋼大門", "south",DOOR_CLOSED);
  setup();
}

int valid_leave(object me, string dir)
{

  if(dir=="north" && me->query("gender")== "男性" && !present("board",me))
      return notify_fail("男人是無法進入瑤光門的!除非你有教主的令牌!!\n");
  
      return ::valid_leave(me,dir);
}
    
