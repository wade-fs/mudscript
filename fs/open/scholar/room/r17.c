// Room: /u/j/judd/room/r17.c
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "儒門中堂書房");
	set( "build", 1 );
  set ("long", @LONG
這裡是江湖上有名的奇俠「九指書生」聖賢書所在之地﹐書房
雖然看起來十分的簡陋﹐卻有十分不平凡的氣魄﹐足足顯示讀書人
的文學之氣﹐在這邊的牆上有一幅畫﹐畫中寫著幾行字﹕
 
          「山不在高﹐有仙則名
            水不在深﹐有龍則靈
            居陋室者﹐聖賢書也」 
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"study.c",
  "south" : __DIR__"r20.c",
  "down" : __DIR__"eqroom",
]));
  set("objects", ([ /* sizeof() == 1 */
   "daemon/class/scholar/master_sue" :1,
]));
  set("light_up", 1);
  set("valid_startroom", 1);

  setup();
        call_other("/obj/board/sue_b", "???");
}



void init()
{
  add_action("do_enter","enter");
}

int do_enter(string str){

 object me = this_player();
if(me->query("liyu")==5)
    me->move("/open/gsword/room/appo/liyu1.c");  
 return 1;
}
int valid_leave(object me, string dir)
{
if (dir == "down" || dir == "north")
	if ( !wizardp (me) && me ->query("family/family_name") != "儒門")
     return notify_fail("那個房間只有儒門弟子才能進去。\n");
     return :: valid_leave(me, dir);
}

