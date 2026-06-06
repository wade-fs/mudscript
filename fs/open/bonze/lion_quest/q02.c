//本房間參考/open/center/room/mail 會自動遞道具給玩家
inherit ROOM;
#include <ansi.h>
//#include "bonze.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
//例如：重新編譯 /u/b/blazakira/bonzee/room/q01.c﹕編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 57: Redeclaration of function init. <===
//　　　編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 102: Redeclaration of function do_check. <===
//兩個檔案不能重複相同的函數名稱 如：init & do_check

void create ()
{
  set ("short", "林間小徑");
  set ("long", @LONG
你走在通往少林寺後山的林間小徑上，走著走著你漸漸地聽不
見少林弟子練功時整齊劃一的口令聲。你的耳根子逐漸地清靜下來
，你正好可以思索著剛剛那一位壯漢嚴肅的行為背後的意義。

LONG);

  set("light_up", 1); //驛站 所以點燈
  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"q01.c",
    "west" : __DIR__"q03.c",
//	"down" : __DIR__"q18.c",//設定快捷路線 以後需砍
	]));
  set("objects", ([ /* sizeof() == 1 */
/* //測試強度用的風雨樓三大exp 900w 之mob 
  "/u/b/blazakira/bonzee/npc_test/w_lin-mo.c" : 1,
  "/u/b/blazakira/bonzee/npc_test/w_shon-to.c" : 1,
  "/u/b/blazakira/bonzee/npc_test/w_charn-kai.c" : 1,
*/
  ]));
  setup();
}

void do_check(object me)
{
      if(me->query("combat_exp" ) < 4500000 && userp(me) && living(me))
       {
		  message_vision(HIC"\n抱歉，前方的路對$P來說太艱辛了，大俠$N請回吧！\n"NOR,me);
		  me->move("/open/bonze/room/r2");
       }
}


void init()
{
  object note;

  if( !this_player()->query_temp("note_ob") ) {
    note = new(__DIR__"obj/note.c");
	this_player()->set_temp("note_ob",1);
    if (note->move(this_player()))
      write (HIC"驛站掌櫃的一看你踏進門來, 馬上哈腰遞給你一張宣傳單。\n\n"NOR);
  }

  add_action ("do_home", "home");
  add_action ("do_home", "ho");
  add_action ("do_home", "hom");
  add_action ("do_goto", "goto");
  add_action ("do_goto", "got");
	  call_out("do_check",1,this_player()); //呼叫函數
}

int valid_leave(object me, string dir)
{
        object note;
        if( me->query_temp("note_ob") ) {
		tell_object(me, HIC"你不以為意的隨手將宣傳單遞了回去。\n\n"NOR);
		me->delete_temp("note_ob");
		destruct(present("note",me));
		}
        return 1;
}

int do_home(string arg)
{
  object note, me;

  me = this_player();
  if( note = me->query_temp("note_ob") ) {
		tell_object(me, HIC"你不以為意的隨手將宣傳單遞了回去。\n\n"NOR);
		me->delete_temp("note_ob");
		destruct(present("note",me));
  }
  
  return 0;
}

int do_goto (string arg)
{
  object note, me;

  me = this_player();
  if( note = me->query_temp("note_ob") ) {
		tell_object(me, HIC"你不以為意的隨手將宣傳單遞了回去。\n\n"NOR);
		me->delete_temp("note_ob");
		destruct(present("note",me));
  }
  
  return 0;
}
