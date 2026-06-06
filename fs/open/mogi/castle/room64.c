// by roger 加上 war by ACKY
inherit ROOM;
#include <ansi.h>
void create () {
	set( "short" , HIR + "焚天魔殿" + NOR);
	set( "build", 87 );
	set( "long"  , "
    這裡就是魔王的所在! 這裡非常的寬敞, 所有的佈置都呈現火
紅色, 甫進門就覺得一股灼熱的氣息撲面襲來, 當中的寶座上坐著
一個全身散發著火焰的人, 全身盔甲護身, 最奇異的是他那對眼睛
竟然分別射出金光和銀光, 透著無比的威嚴, 令人不禁心生畏懼, 
氣勢為之大挫!
");

        set("evil", 1);
        set("king-room",1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ 
            "west"  : __DIR__"room63",
            "north"  : __DIR__"room66",
            "south"  : __DIR__"room65",
      ]));

        set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/fire-king" : 1,
      ]));

        setup();
}

int valid_leave(object me, string dir)

{
        if(dir=="north"&&present("king",environment(me)))
  {

message_vision(HIY + "焚天魔王喝道:「竟敢在我眼前放肆！」\n" + NOR,me);

return 0;
}
return 1;
}

void war_start()
{
	shout( HIR + "\n\n\n\t魔界眾魔因焚天魔王之死開始忿怒\n\n"+
		  "\t眾魔們殺氣騰騰\n\n"+
		  "\t群魔離開魔界朝人間殺去!\n\n\n\n" + NOR );

	new("/open/mogi/dragon/npc/dragon-gold.c") ->move("/open/capital/room/r70");
	new("/open/mogi/castle/npc/seven-dark-4.c")->move("/open/capital/room/r70");
	new("/open/mogi/castle/npc/seven-dark-5.c")->move("/open/capital/room/r70");
	new("/open/mogi/castle/npc/seven-dark-6.c")->move("/open/capital/room/r70");
	new("/open/mogi/castle/npc/black-ghost.c" )->move("/open/gsword/room/su3");
	new("/open/mogi/castle/npc/seven-dark-1.c")->move("/open/gsword/room/su3");
	new("/open/mogi/castle/npc/seven-dark-2.c")->move("/open/gsword/room/su3");
	new("/open/mogi/castle/npc/seven-dark-3.c")->move("/open/gsword/room/su3");
	new("/open/mogi/castle/npc/white-ghost.c" )->move("/open/start/room/s5.c");
	new("/open/mogi/castle/npc/seven-dark-4.c")->move("/open/start/room/s5.c");
	new("/open/mogi/castle/npc/seven-dark-5.c")->move("/open/start/room/s5.c");
	new("/open/mogi/castle/npc/seven-dark-6.c")->move("/open/start/room/s5.c");
	new("/open/mogi/castle/npc/black-ghost.c" )->move("/open/ping/room/road4");
	new("/open/mogi/castle/npc/seven-dark-4.c")->move("/open/ping/room/road4");
	new("/open/mogi/castle/npc/seven-dark-5.c")->move("/open/ping/room/road4");
	new("/open/mogi/castle/npc/seven-dark-6.c")->move("/open/ping/room/road4");
	new("/open/mogi/castle/npc/white-ghost.c" )->move("/open/port/room/r3-1");
	new("/open/mogi/castle/npc/seven-dark-1.c")->move("/open/port/room/r3-1");
	new("/open/mogi/castle/npc/seven-dark-2.c")->move("/open/port/room/r3-1");
	new("/open/mogi/castle/npc/seven-dark-3.c")->move("/open/port/room/r3-1");	
}

