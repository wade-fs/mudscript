#include "/open/open.h"

inherit F_VENDOR;

string do_ask ();

void create()
{
	set_name("賣茶的老人", ({ "old man", "man" }) );
	set("nickname","駝老");
	set("gender", "男性" );
	set("age", 62);
	set("combat_exp",54);
	set("long", @LONG
你正盯著一位賣茶水的老人，瞧他的樣子，應該是滿經風霜的
江湖過來人，他的手上拿著一包東西，不知是什麼名堂。
LONG);

	set("vendor_goods", ({
	    MAIN_OBJ"bento",
	    MAIN_OBJ"tea",
	}) );

	set("greeting_msg", ({
 	    "駝老說道: 客倌買壺茶喝吧!\n",
	}) );
	set("chat_chance", 8);
	set("chat_msg", ({
	    "駝老說道: 對付真正高手用硬砍的是不行的。\n",
	    "駝老說道: 可惜不知道哪裡有真正無色無味的蒙汗藥。\n",
	    "駝老說道: 角落那個好漢在這兒呆好久了，一壺茶都快喝光了。\n",
	    "駝老說道: 誰都知道真正高手是鋒芒不露的。\n",
	    "駝老說道: 客倌您知道蒙汗藥嗎? 我找半天找不到。\n",
	}) );
	set("inquiry", ([
	    "硬砍"	:	"聽聽老人言吧，硬砍不如下藥的好。",
	    "茶"	:	"客倌，買一壺茶吧。",
	    "真正高手"	:	"放眼天下，足以稱為真正高手的，我看只有燕南天了吧。",
	    "高手"	:	"我還高腳咧。",
	    "哭風坡"	:	"這兒不就是哭風坡了嗎?",
	    "蒙汗藥"	:	"我手上這包不知是也不是？不過，我死也不會給你的。",
	    "好漢"	:	"他手上拿著一把生鏽的鐵刀，據說他是傳說中的燕南天。",
	    "燕南天"	:	(: do_ask :),
	    "大俠燕南天":	(: do_ask :),
	]) );
	setup();
	carry_object(CENTER_OBJ"cloth1")->wear();
	add_money("silver", 10);
}

string do_ask()
{
  object	ob, env=environment(this_object());

  if (!ob=present("day", env)) {
    ob = new(MAIN_NPC"day");
    if (ob) ob->move(env);
    if (random(2))
      return "噓，您瞧，他不就在那兒嗎?!....小心他手中那把劍。\n";
    else
      return "你再看仔細，他不就在你旁邊?\n";
  }
  return "您看，他正瞪著您看呢，客倌小心一些應付吧。\n";
}

int accept_fight(object me)
{
  return notify_fail ("駝老說道: 饒了我吧，我這把骨頭哪裡還能拆招解招哩。\n");
}

void die()
{
  object	me;

  me = this_object()->query_temp("last_damage_from");
  if (!me) me = this_object();
  tell_object(me, "...............\n");
  if (me->query_temp("quests/badman_license")) {
    tell_room(environment(),
	sprintf ("從%s的手裡滾出一包紙包，不知是什麼東西。\n",
	this_object()->name()) );
    new(MAIN_OBJ"paper")->move(environment());
    tell_room(environment(), sprintf ("%s被殺死了。\n",
	this_object()->name()));
  }
  ::die();
}
