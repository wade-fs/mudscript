inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "密林迷陣");
        set ("long", @LONG
兩旁的古木高聳入雲，樹葉漫天遮蔭，在微弱的光線下，前方的
路總是迷濛看不清，兇猛的野獸叫聲忽遠又忽近，詭異的氣氛下，心
情總是起伏不定，看看回頭的路也已被黑暗淹沒了，也許你只有永遠
的迷失在這密林之中了。
LONG);  
	set("no_auc", 1);
	set("no_transmit", 1);
	set("light_up",0);

        set("exits", ([ /* sizeof() == 4 */
	]));

        setup();
}

void init()
{
	object me,ob;
	int os;
	me = this_player();

	if( me->query("quests/can_go_magic-manor") == 1 )
	{
	  if( present("magic sign",me) )
	  {
	  ob = present("magic sign",me);
	  os = ob->query("magic-manor");
	    if( os == 6 )
	    {
	    call_out("msg1",3,me);
	    }
	  }
	}
}

int msg1()
{
	object me;
	me=this_player();
        tell_object(me,HIC + "只見你身上的聚靈引發出一道光芒指向東方。\n" + NOR);
	add_action("do_go","go");
}

int msg2()
{
	object me;
	me=this_player();
        tell_object(me,HIC + "只見你眼前豁然開朗，經過千辛萬苦，終於來到傳說中的聚靈山莊。\n" + NOR);

}

int do_go(string str)
{
	object me,obj,ob;
	int os;
	obj = this_object();
	me = this_player();
	ob = present("magic sign",me);
	os = ob->query("magic-manor");

	if(str == "east" )
        if( present("magic sign",me) && os == 6 && me->query("quests/can_go_magic-manor") == 1 )
	{
	tell_room(obj,"聚靈引光芒所到，暗不透光的密林出現出了一條路。\n");
	message_vision("$N在聚靈引開路下，慢慢走向那一條路。\n",me);
	call_out("msg2",2,me);
	tell_room(obj,"隨著光芒漸漸散去，光芒所指的路也消失無蹤。\n");
	me->move("/open/magic-manor/manor50");
	return 1;
	}
}
