// wulai.c by bigcat

inherit NPC;

string do_ask1();
string do_ask2();

void create()
{
	set_name("無賴", ({ "wulai", "human" }) );
	set("race", "人類");
	set("age", 30);
	set("long", "。\n");
	
	set("str", 26);
	set("cor", 25);
	set("combat_exp",300);

	
	set("chat_chance_combat",5);
	set("chat_msg_combat", ({
		"無賴大叫一聲:大爺來收保護費了,不想死的就乖乖的交出來!\n",
		"無賴大剌剌的走過來,向你吐了一口膿痰。\n"
	}) );
		
	set("chat_chance", 5);
	set("chat_msg", ({
	    "無賴說道: 聽說移花宮有一個宮女潛藏在妓院，可是就不知妓院在哪。\n",
	    "無賴說道: 聽說有個水仙姑娘傾城傾國，真想一親芳澤。\n",
	    "無賴說道: 能看到傳說中的水仙姑娘，死也瞑目了。\n",
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
	set("inquiry", ([
	    "燕南天"	:	"啊，快躲起來，我最怕他了。",
	    "水仙姑娘"	:	(: do_ask1 :),
	    "麗春院"	:	"是聽我兄弟說過那兒，不過沒逛過，可惜。\n",
	    "移花宮"	:	(: do_ask2 :),
	]) );

	setup();
       add_money("coin",100);
}

string do_ask1()
{
  int	query;
  object me=this_player();

  query=me->query_temp("quests/help_water_god");

  if (!query || query != 1  || me->query("quests/help_water_god"))
  {
      switch (random(5)) {
	case 0:
	  return "水仙姑娘是你的老相好嗎? 介紹給我吧。\n";
	  break;
	case 1:
	  return "請問你知道水仙姑娘在哪一家窯子? 帶我去見識見識。\n";
	  break;
	case 2:
	  return "我又不是水仙姑娘，問我這幹嘛。\n";
	  break;
	case 3:
	  return "我不認識什麼水仙杜鵑的，去去去。\n";
	  break;
	default:
	  return "誰知道誰是誰啊。\n";
      }
  }
  else {
    me->set_temp("quests/help_water_god", 2);
    if (random(2))
      return "水仙姑娘聽說正在逃亡當中，全部的希望就靠大俠燕南天了。\n";
    else
      return "水仙姑娘犯了移花宮的大忌，現在正在被追殺哩。"+
	     "無賴嘆了口氣，說道: 不知燕南天會不會出手解救。\n";
  }
}

string do_ask2()
{
  if (random(2))
    return "移花宮? 又有誰知道在哪兒了，只不過是謠傳罷了。\n";
  else
    return "我還種樹宮咧，去你Ｘ的宮啦，別來煩人。\n";
}
