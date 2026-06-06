// one.c by oda

#include "/open/open.h"
#include <ansi.h>

inherit NPC;

string do_cure();
string stop_bleed();
string cure_poison();
string do_ask();

void create()
{
	set_name("萬春流", ({ "one tsun liu", "one", "liu" }) );
	set("title", "神醫");
	set("gender", "男性");
	set("age", 49);
	set("attitude", "peaceful");
	set("combat_exp", 100000);
	set("no_kill", 1);
	set("long", "你看到一個中年男子，身著長袍黃冠，羽衣飄飄，瀟然出塵，\n神情看來說不出的和平寧靜。\n他是惡人谷中唯一的醫生，所以在惡人谷中的人都靠他治病。\n");
	set("str", 22);
	set("cor", 20);
	set("int", 33);
	set("spi", 30);
	set("cps", 32);
	set("con", 28);

	set("chat_chance", 3);
	set("chat_msg", ({
		"萬春流歎了口氣，喃喃道：唉..不知道有誰能救得了他..\n",
		"萬春流搖了搖頭說：可真苦了小魚兒這孩子。\n",
	}) );
	
	set("inquiry", ([
	//"他"	:	(: do_ask1 :),
	//"小魚兒":	(: do_ask2 :),
    "惡人森林" : "你想去惡人森林.. ?我也只是聽說而已 ,詳細位置整個惡人谷也只有杜殺和軒轅三光那個爛賭鬼知道而已...\n",
	"療傷"	:	(: do_cure :),
	"止血"	:	(: stop_bleed :),
	"解毒"	:	(: cure_poison :),
    "破廟"  :   (: do_ask :),
	]));

	setup();
}

int accept_fight(object me)
{
	return notify_fail("萬春流笑著對你說：這位"+RANK_D->query_respect(me)+"別開玩笑了好嗎?\n");
}

string do_cure()
{
	int kee, ekee, mkee;
	object who;
	who = this_player();
	ekee = who->query("eff_kee");
	mkee = who->query("max_kee");

	if( ekee==mkee ) return "你不是好好的？哪有受傷？";
	if( ekee>=mkee*8/10 ) return "你的傷勢不算嚴重，自己多休息就好了。";
	kee = (mkee*8/10 - ekee);
	if( !who->can_afford(kee*100) )
		return "對不起，以你傷勢而言，只有這點錢恐怕幫不了你。";
	who->pay_money(kee*100);
	who->set("eff_kee", mkee*8/10);
	message_vision("萬春流檢查了一下$N的傷勢，並且拿了幾帖外傷藥敷在$N的傷口上。\n", who);
	tell_object(who, HIC + "你感覺到身上的傷口好多了。\n" + NOR);
	return "好了，這位"+RANK_D->query_respect(who)+"，以後記得小心一點喔。";
}

string stop_bleed()
{
	int bleed;
	object who = this_player();

	if( !bleed = who->query_condition("bleeding") )
		return "你哪裡流血了？流鼻血我可不治。";
	if( !who->can_afford(500*bleed) )
		return "對不起，以你傷勢而言，只有這點錢恐怕幫不了你。";
	who->pay_money(500*bleed);
	message_vision("你看到萬春流以極熟練的手法迅速的幫$N敷藥並包紮傷口。\n", who);
	who->apply_condition("bleeding", 0);
	tell_object(who, HIC + "你的傷口停止流血了。\n" + NOR);
	return "這樣應該就可以了。";
}

string cure_poison()
{
	int snake, coldpoison;
	int dark, five, rose, fire;
	object who = this_player();
	coldpoison = 0;

	if( who->query_condition("spring") ) {
		command("grin");
		return "陰陽合和散是沒有解藥的，你自己愛偷吃，我也沒辦法啦。";
	}
	snake = who->query_condition("snake_poison");
	if( dark = who->query_condition("dark_poison") )
		coldpoison += dark;
	if( five = who->query_condition("five_poison") )
		coldpoison += five;
	if( rose = who->query_condition("rose_poison") )
		coldpoison += rose;
	if( fire = who->query_condition("fire_poison") )
		coldpoison += fire;

	if( !coldpoison && !snake )
		return "老夫實在是看不出你中的是什麼毒。";
	if( coldpoison && coldpoison<=3 ) {
		tell_object(who,"萬春流搖搖頭說：你中的天冰奇毒已經沒辦法再減輕了。\n");
	} else if( coldpoison ) {
		tell_object(who,"萬春流皺著眉頭說道：你中了冥魔教的天冰奇毒，我只能試著幫你減輕毒性看看了。\n");
		if( !who->can_afford(coldpoison/2*20000) )
			return "對不起，你的錢買不起這麼貴的解藥。";
		who->pay_money(coldpoison/2*20000);
		if( dark ) who->apply_condition("dark_poison", dark/2);
		if( five ) who->apply_condition("five_poison", five/2);
		if( rose ) who->apply_condition("rose_poison", rose/2);
		if( fire ) who->apply_condition("fire_poison", fire/2);
	}
	if( snake ) {
		tell_object(who, "萬春流看了看你說到：你中了蛇毒喔。\n");
		if( !who->can_afford(500*snake) )
			return "對不起，你身上的錢不夠用來解你的蛇毒喔。";
		who->pay_money(500*snake);
		who->apply_condition("snake_poison", 0);
	}
	message_vision("萬春流仔細的檢查了一下$N的狀況，便轉身從櫥櫃上的一個罐子裡\n拿了幾顆黑色藥丸，放在$N的口中。\n", who);
	tell_object(who, "一陣強烈的臭味從你嘴裡傳了出來，令人作嘔，你只好捏住鼻子一\n口氣把藥丸吞了下去。\n");
	if( coldpoison )
		tell_object(who, HIC + "你感覺到體內的毒性減弱不少。\n" + NOR);
	else
		tell_object(who, HIC + "你感覺到舒服多了。\n" + NOR);
	return "良藥苦口，你就忍忍吧。";
}

string do_ask()
{
  int me;
  object who = this_player();
  if(who->query_temp("marks/karup2")!=1)
  {
   return "什麼破廟？惡人谷哪有這種東西？\n";
  }
  else
  {
   who->set_temp("marks/allow",1);
message_vision("萬春流說道﹕唉，這兩個該死的女人！啥都跟你說了！
好吧，這破廟可是在惡人森林的某個地方，去找軒轅三光吧。
但可別說是我讓你去的啊！不然杜殺知道了，你我都麻煩！\n",who);
  return "可千萬別講啊！\n";
  }
}
