//open/prayer/room/1-door2

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇待客門");
  set ("long", @LONG

      ''';;'                                            ;;
          ;;  ,,,,,;;,            ';,                   ;;      ,,
    ;  ;' ;;  ;;' ,;;'             ;;                 ;;;; ,,   ;;
   ;;  ,, ;;  ;; ;;;               ;'    ;;            ;; ,;;, ,;'
   ;; ,;;;;;  ''''''         ,     ;  ,,;;'            ' ,;;' ,;;,;;;;
     ,;,' ;;                ;;,   ;;''''               ,;;    ';'
    ;;'  ';;,,,,            ;;'   ;;                ,,;;;';;;    ';
          ;;;''                  ,;              ;;;',;; ,'', ',,;'
           ,;;;                ,;;'  ';;,,,         ;;'  ',;'   ;;,
          ';;'               ,;;'       ';;;;,,    ''  ,,;;'   ,;';;,,
         ,;;,,,,           '''             ';;;      ,;;',;  '''   ';;;,
        ;;;''''''                                     ''';'          '''

LONG);

        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/door-looker" : 3,
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 2 */
      "enter" : "/open/prayer/room/train1-17",        //'練武場
	"south" : "/open/prayer/room/westarea/road1",		//`馬路
]));

  setup();
}
 
