
#include <ansi.h>
#include "/open/open.h" 
inherit F_SOLDIER;
void create()
{
	set_name("將軍",({"general"}) );
	set("long","
一位武藝不凡的將軍，身上穿著鎧甲，手上拿著寶劍，看起來十分威武。
據這裡的村民說這位將軍是在一次戰役中負傷逃到此處，經村民救助後被
這裡的風土人情深深的吸引，因此決定在此定居。\n");
	set("age",30);
	set("str",30);
	set("con",30);
	set("attitude","heroism");
	set("officer_power",50);
	set("max_officer_power",50);
	set("class","officer");
	set("soldier_list",([
	"soldier" : "兵士(soldier)",
	"fighter" : "武士(fighter)",
	"guard" : "守衛(guard)",
]) );
	set("soldier_lv",([
	"soldier" :5,
	"fighter" :10,
	"guard"   :15,
]) );
	set("max_kee",500);
	set("max_gin",500);
	set("max_sen",400);
	set("combat_exp",150000);
	set_temp("apply/armor",20);
	set_temp("apply/dodge",20);
	set_temp("apply/attack",30);
	set_skill("literate",60);
	set_skill("unarmed",40);
	set_skill("sword", 40);
	set_skill("blade",50);
	set_skill("move",40);
	set_skill("dodge",45);
	set_skill("nine-steps",40);
	set_skill("parry",45);
	set_skill("her-blade", 50);
	map_skill("move","nine-steps");
	map_skill("parry","her-blade");
	map_skill("dodge","nine-steps");
	map_skill("blade","her-blade");
	set("gender","男性");
	set("chat_chance_combat", 8);
	setup();
	add_money("gold",5);
	carry_object("/open/poison/obj/boots.c")->wear();
	carry_object("/open/poison/obj/plate.c")->wear();
	carry_object("/open/poison/obj/tblade.c")->wield();
	carry_object("/open/poison/obj/cloak.c")->wear();
	carry_object("/open/poison/obj/helmet.c")->wear();
}

void die()
{
	object me;
	me=query_temp("last_damage_from");
	message_vision("\n",me);
	message_vision(HIR "一大蓬的鮮血濺在你的臉上。\n" NOR,me);
	message_vision(" 將軍的身體倒在血泊中微微地顫抖著。\n",me);
	tell_room(me,"將軍說:你......你會害死村裡的人....的。\n");
	call_out("msg2",1,me);
}
 void msg2(object me)
{	 
	message_vision("\n",me);
message_vision(HIG "山賊嘍囉大叫:那個惹人厭的將軍死掉啦，哈哈哈!!\n" NOR,me);

message_vision(HIG "山賊頭目喊道:小子們，傢伙準備好，要開工啦!!!\n" NOR,me);
	tell_room(me,"你不禁心想:糟!犯大錯了。\n");
	new("/open/poison/npc/bandit4.c")->move("/open/poison/room/v2-6.c");
	new("/open/poison/npc/bandit2.c")->move("/open/poison/room/v2-6.c");
	new("/open/poison/npc/bandit1.c")->move("/open/poison/room/v2-4.c");
	new("/open/poison/npc/bandit1.c")->move("/open/poison/room/v2-4.c");
	new("/open/poison/npc/bandit2.c")->move("/open/poison/room/v2-2.c");
	new("/open/poison/npc/bandit1.c")->move("/open/poison/room/v2-2.c");
	new("/open/poison/npc/bandit1.c")->move("/open/poison/room/v2-1.c");
	new("/open/poison/npc/bandit1.c")->move("/open/poison/room/v2-8.c");
	::die();
	return 0;

}
