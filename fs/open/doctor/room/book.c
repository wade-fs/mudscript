#include <ansi.h>
inherit ROOM;
string random_road();

string *dirs = ({
  "north","south","east","west"
});

void create ()
{
  set ("short", "藏經閣門口");
	set( "build", 12 );
  set ("long", "
" + HIY + "             ;;                ,            ,,          ,;;,     '''';;" + NOR + "
" + HIY + "     ';,    ;;;'''            ,;'     ,,;''''             ;'   ; ,,  ;;" + NOR + "
" + HIY + "      ';   ''     ',         ,;'            ,,          , ',   ;     ;;" + NOR + "
" + HIY + "   ;'  '   ,,;,;'          ,;',,,    ;  ,'  ;'     ;     ,;    ;;''  ;;" + NOR + "
" + HIY + "       ;''''';;           ;;;';;'   ;'  ;,  ,,,    ;   ;' ,;;,,,     ;;" + NOR + "
" + HIY + "   , ;    ,;;;;           '  ;',,   ';  ''    ''   ;     ,'  ;;      ;;" + NOR + "
" + HIY + "   ;,;; ;  ;, '; ,;         ;;';;    '             ;      ';;''''''  ;;" + NOR + "
" + HIY + "   ,,; ,; '';' ';;'           ;'       ,,,;''      ;     ,;'  ,,,    ;;" + NOR + "
" + HIY + "  ;',; ;; ,;,, ,;;          ,; ,         ;        ;;      , '' ;;    ;;" + NOR + "
" + HIY + " ,' ;; ;; ' ;' ' ';,       ,;;;'        ,; ,,,,   ;;      ;  , '     ;;" + NOR + "
" + HIY + "   ';  ;;,,;;     ';;,,,    ''     ,;;;'''''''''  ;;                ,;;" + NOR + "
" + HIY + "        '           ';;;                           '                ';;" + NOR + "
");
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"book2",
  "out" : __DIR__"2",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/doctor/npc/b-guard.c" : 2,
]));
  set("light_up", 1);
  setup();
}

int valid_leave(object me , string dir)
{
/* //不能用 因為save_die 要用入閣令做判斷 by blazakira
  if(dir=="enter" && present("book_mark",me))
  {
    tell_object(me,"你將" + HIY + "入閣令" + NOR + "交給護閣守衛後進入藏經閣之內。\n\n");
    destruct(present("book_mark",me));
  }
*/
  if(dir=="enter" && !present("book_mark",me))
    return notify_fail(HIW + "護閣守衛發出一股浩然正氣阻擋你進入藏經閣之內！\n" + NOR);
  else if(dir=="enter" && me->query("quest/doctor_book/allow")==1)
    me->set_temp("quests/doctor_book/allow",1);
  return ::valid_leave(me,dir);
}

void reset()
{
  for(int i = i ; i<= 10; i ++)
  {
    tell_room(sprintf(resolve_path(__DIR__,"../room/book%1d.c"),i),HIG+
      "糟糕！你因為走得太累而稍微倚靠在書架旁時，正好成了壓倒駱駝的最後一根稻草，\n"+
      "使得書架倒塌了不少使得離開的路徑與先前不同囉。\n" + NOR);
  }
  random_road();
  ::reset();
}

string random_road()
{
  object room;
  object prevroom;
  string to,from;
  prevroom = load_object(__DIR__+"book2.c"); //上一間房間 //一開始當然是第一間 但是book1 多一個出口 所以改book2
  for(int i = 2 ;  i<= 9 ; i++) //保留第一間的出口
  {
    room = load_object(sprintf(__DIR__+"book%1d",i));
    room->delete("exits");
  }
  for(int i = 3 ; i <= 9 ; i++) //最後一間時 出口數只有一個
  {
    room = load_object(sprintf(__DIR__+"book%1d",i)); //迴圈開始 設重新讀取的第i間房間
    while(from = dirs[random(sizeof(dirs))]){ //進入的入口
      if(!prevroom->query("exits/"+from)) break; //上一間房間若是沒有出口(exits) 就跳出
    }

    to = DIR_D->oppdir(from);
    room->set("exits/"+to , base_name(prevroom));
    for(int j = 0 ; j < sizeof(dirs) ;j++)
    {
      if(!prevroom->query("exits/"+dirs[j]))
      {
        prevroom->set("exits/"+dirs[j],sprintf(__DIR__+"book%1d",random(2)+1));
      }
    }
    prevroom->set("exits/"+from , base_name(room));
    prevroom = room; //將當前房間設為上一間房間 以待迴圈下個動作
  }
}
