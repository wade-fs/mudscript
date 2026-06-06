// sparrow.c by oda
// use in /open/center by powell

inherit NPC;

void create()
{
	set_name("音鵲", ({ "music-bird","bird" }) );
	set("long",@LONG
         不知從哪裡飛來的奇鳥, 鳴
         聲悅耳如歌, 羽色綻著藍光
         十分漂亮. 
LONG);
	set("race","野獸");
	set("age", 2);
	set("str", 8);
	set("con", 9);
	set("max_gin", 60);
	set("max_kee", 180);
	set("max_sen", 60);

	set("limbs", ({ "尖嘴", "翅膀", "左腳", "右腳", "爪子" }) );
        set("verbs", ({ "claw", "poke" }) );
	set("chat_chance", 4);
	set("chat_msg", ({
		"ㄍㄨ～～ㄍㄨ～～。\n",
	}) );
		
	set("combat_exp",4000);
	setup();
	add_money("coin", 1);
}
