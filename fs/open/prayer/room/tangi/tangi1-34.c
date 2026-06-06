
//open/prayer/room/tangi/tangi1-34.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","大門");
        set("long",@LONG
	
                             ,,         ,           ,;;;;;,,   ,,,,,,,,
     '''''';;''''''          ;;   ,;;, ;; ,,;,      ;;,,,,;;   ;,,,,,;;
           ;;             ,,,;;,,';,,;';; ;,,;'     ;;'''';;   ;''''';;
     ,,,,,,;;,,,,,           ;;  ,;'';;'; ,;';,     ;;,,,,;;   ;,,,,,;;
     '''''';;'''''          ,;;;, ''''  ; '';',;    ;;'''''          ;;
          ,;;;,           ,;';; ',,,,,,,;;,,,,;,,   ;'               ;;
        ,;'   ';,,       ;;' ;;    ,;    ;, ,;,    ;;                ;;
     ,,;'       ';;,,        ;;   ,;;;,,  ;;;'    ,;'                ;;
 ,;;;''           ';;;;,,    ;; ,;;'   ',;'';;,,,;;'                 ';,
  '                  '''     ''         '     '''''                   ''

LONG);
        set("item_desc", ([ /* sizeof() == 1 */
        "north" : (: look_door,     "north" :),
]));

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"tangi1-31",		//練武場
        "east":"/open/prayer/room/westarea/road10",	//馬路
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/door-looker" : 2,		//大門守衛 
   		
]));
        set("light_up", 1);
        create_door("north","聖火刻紋精鋼大門", "south",DOOR_CLOSED);
  setup();
}
