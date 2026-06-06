// crazy_dog.c

inherit NPC;

string do_ask();
string do_ask1();

void create()
{
	set_name("地痞", ({ "dipi", "human" }) );
	set("race", "人類");
	set("age", 30);
	set("long", "一雙兇惡的眼神鄭上下打量著你。\n");
	
	set("str", 30);
	set("cor", 27);
	set("combat_exp",340);

	
	set("chat_chance_combat",4);
	set("chat_msg_combat", ({
		"地痞神不知鬼不覺的打了你一記耳光\n",
		"地痞突然狂性大發,七拳八腳的向你揮了過來。\n",
	}) );
	set("chat_chance", 5);
	set("chat_msg", ({
		"地痞說道: 大俠燕南天是個真英雄。\n",
		"地痞說道: 說起大俠燕南天，真的是令黑白兩道都拜服的豪傑。\n",
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
	set("inquiry", ([
	    "惡人證"	:	"是有聽說這回事，擁有它才能順利進入惡人谷。",
	    "惡人谷"	:	"惡人谷不就在崑崙山嗎? 但..從來沒有人找得到路。",
	    "崑崙山"	:	"地圖上不就有了嗎?",
	    "地圖"	:	"自己去買一本吧。",
	    "義弟"	:	"誰是你義弟啊，也不自己照照鏡子。",
	    "江楓"	:	"聽說他微微的一笑，就足以讓女子神魂顛倒，我要有這本領就好了。",
	    "燕南天"	:	(: do_ask :),
	    "大俠燕南天":	(: do_ask :),
	    "哭風坡"	:	(: do_ask1:),
	]) );

	setup();
       add_money("coin",50);
}

string do_ask()
{
  int	query;
  object me=this_player();

  query=me->query_temp("quests/badman_license");

  if (!query || query != 1 || me->query("quests/badman_license"))
  {
      switch (random(5)) {
	case 0:
	  return "燕南天誰人不知何人不曉，這問題拿來問我，是尋人開心嗎?\n";
	  break;
	case 1:
	  return "燕南天神龍不見尾，我也不知他老人家身在何處。\n";
	  break;
	case 2:
	  return "燕南天三個字是你隨口說說的嗎?\n";
	  break;
	case 3:
	  return "幸好我沒做什麼傷天害理的大事，不然哪能逃離燕南天的手中。\n";
	  break;
	default:
	  return "求求您別在我面前提燕南天三個字好嗎?\n";
      }
  }
  else {
    me->set_temp("quests/badman_license", 2);
    if (random(2))
      return "燕南天聽說為了搭救他的義弟江楓，已經趕去哭風坡了。\n";
    else if (random(2))
      return "這幾天以來，聽說燕南天為了他的義弟江楓心急如焚，"+
		"此刻已追趕去哭風坡了。\n";
    else
      return "聽說燕南天日夜兼程趕去哭風坡搭救他義弟，卻沒人知道誰是燕南天。\n";
  }
}

string do_ask1()
{
  object me=this_player();
  int	query1, query2;

  query1=me->query_temp("quests/badman_license");
  query2=me->query_temp("quests/help_water_god");

  if ((query1 && query1 == 2 && !me->query("quests/badman_license")) ||
      (query2 && query2 == 2 && !me->query("quests/help_water_god")))
  {
	if (random(2))
	  return "聽說這地方連地圖上都沒有記載，卻不知燕大俠是怎麼找去的。";
	else
	  return "有人拿著地圖跑去京城到處問人，也不知有沒有問到。";
  }
  else
	if (random(2))
	  return "哭風坡? 只聽說有這地方，到底在哪兒我也不知道。\n";
	else
	  return "哭風坡? 大概是專門哭爹哭媽的地方吧，我沒興趣。\n";
}
