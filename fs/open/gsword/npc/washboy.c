// crazy_dog.c

inherit NPC;

void create()
{
set_name("仙劍派 小劍童",({"swordboy","boy"}));
	set("race", "人類");
	set("age", 13);
	set("long", "他手執掃帚，氣定神閒專心的打掃著這無盡的石階。\n");
	set("attitude", "peaceful");
	set("str", 17);
	set("cor", 15);
	set("combat_exp", 5);
	set("chat_chance", 6);
	set("chat_msg",({
"小道童喃喃道︰真是倒楣，每次都被那兩個醉鬼，賭鬼師叔奴役，一下叫我打掃石
階一會而又叫我幫他們搥背按摩，改天我一定要跟師父告狀。\n",
"小道童喃喃道︰不過聽一些年長的師兄們說，那兩個醉鬼，賭鬼師叔當年可也曾經
叱咋江湖，好像還曾經追隨祖師爺斬魔除妖，不過，看他們現在這個樣子，我看八成是
假的吧！\n"
	}));
	set_temp("apply/attack", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 2);

	setup();
       add_money("coin",50);
}
