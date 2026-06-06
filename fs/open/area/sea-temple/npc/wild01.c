inherit NPC;
#include <ansi.h>

void create()
{
        set_name("粗野人",({"wild man","man"}));
        set("long","野人村來的獸人，毫無智慧，只會按照上面所吩咐下來作事情，智商十分低。\n");
        set("race","野獸");
        set("attitude","friendly");
        set("limbs", ({ "頭部", "身體", "手臂" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp",400000);
        set("max_gin",5000);
        set("max_kee",10000);
        set("max_sen",5000);
        set("max_force",10000);
        set("gin",5000);
        set("kee",10000);
        set("sen",5000);
        set("force",10000);
        set_temp("can_delete",1);
        set_temp("apply/armor", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/attack", 100);
        set_skill("dodge",200);
        set_skill("move",200);
        set_skill("unarmed",100);
        set_skill("force",200);
        set("force_factor",30);
	set("must_heart_beat",1);
        setup();
}

string *break_msg = ({
	HIR"粗野人不斷飛舞著鐵鎚般的拳頭，敲向周圍還佇立著的圍牆！\n"NOR,
	HIR"粗野人不斷的破壞著圍牆！\n"NOR,
	HIR"粗野人一邊留著口水，一邊敲打著周圍的牆壁！\n"NOR,
	HIR"粗野人用力敲了牆壁後，發覺手很痛，皺了一下眉頭後，又繼續敲打牆壁！\n"NOR,
	HIR"粗野人緩緩的觀看了四周，又繼續敲打牆壁！\n"NOR,
});

void heart_beat()
{
object me,ob,room;
int b,d,msg,i;

	ob = this_object();
	room = environment(ob);
	b = room->query("defence-build");
	
	if ( !b )
	{
		ob->add("steps",1);
		if(ob->query("steps") > 10)			// 走10次還沒辦法破壞牆壁，就直接砍掉..
			destruct(ob);
		ob->set("chat_chance",100);
        	ob->set("chat_msg",({
        	(: random_move :),
        	}));
        return ::heart_beat(1);
	}
	else
	{
		if( ob->query("chat_chance"))
		{
			ob->delete("chat_chance");
			ob->delete("chat_msg");
		}
	}
	
	if ( b < 0 ) { room->set("defence-build",0); return ::heart_beat(1); }
	
	d = random(2)+1;
	msg=random(sizeof(break_msg));
	message_vision(break_msg[msg],ob);
	room->add("defence-build",-d);
::heart_beat(1);
}
