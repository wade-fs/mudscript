// yen.c by wade and oda

#include "/open/open.h"
#include <ansi.h>

inherit NPC;

string do_ask1();
string do_ask2();

void create()
{
	seteuid(getuid());	// 這行一定要
	set_name("司馬煙", ({ "sma yen", "sma", "yen" }) );
	set("nickname", "穿腸劍");
	set("title", "惡人谷小隊長");
	set("class", "bandit");
        set("race", "人類");
        set("gender", "男性");
        set("age", 35);
	set("long", "他手中的那把穿腸劍，以及殺人不眨眼的狠毒性格，在武林中樹敵無數。\n為了逃避仇家的追殺，他逃入惡人谷中躲避，並且受到十大惡人的重用。\n他將十大惡人的武功\融入自己的劍法之中，顯得更具威力。目前他奉命負\n責把守惡人谷的入口。\n");

        set("str", 30);
        set("cor", 30);
	set("max_kee", 1000);
	set("max_force", 500);
	set("force", 500);
	set("force_factor", 5);
	set("combat_exp", 250000);

	set_skill("sword", 75);
	set_skill("parry", 40);
	set_skill("dodge", 30);
	set_skill("move", 30);
	set_skill("force", 30);
	set_skill("badforce", 35);
	set_skill("badsword", 90);
	set_skill("ghost-steps", 40);
	map_skill("sword", "badsword");
	map_skill("dodge", "ghost-steps");
	map_skill("move", "ghost-steps");
	map_skill("force", "badforce");
	map_skill("parry", "badsword");

        set("chat_chance", 8);
        set("chat_msg",({
             "司馬煙說道: 入谷如登天，來人走這邊。\n",
	     "司馬煙瞪了你一眼說: 想入谷？能殺的了我再說吧。\n",
	     "司馬煙垂頭喪氣的說: 來這兒的人，其實大都是為了躲避天下第一神劍的追殺。\n",
	     "司馬煙推了你一把說: 要進谷不難，但是你有這個資格嗎？\n",
        }) );
        set("inquiry", ([
	    "黑白兩道"	:	"俠官謂之白道，賊盜謂之黑道，這點你也不懂?",
            "惡人谷"	:	"惡人谷是黑白兩道具不見容的最後出路。",
	    "天下第一神劍":	"天下第一神劍不就是燕南天嗎?",
	    "進谷"	:	"十大惡人頒布一道通令，有惡人證才准進谷。",
	    "入谷"	:	"十大惡人頒布一道通令，有惡人證才准入谷。",
	    "資格"	:	"資格？殺了燕南天再說吧，哈哈。",
	    "燕南天"	:	(: do_ask2 :),
	    "惡人證"	:	(: do_ask1 :),
	    "惡人證明"	:	(: do_ask1 :),
        ]) );
        set_temp("apply/armor", 100);

        setup();
	add_money("gold", 2);
	carry_object(BAD_OBJ"yensword")->wield();
}

void attempt_apprentice(object who)
{
	command("say 你要加入惡人谷？進去找我們大頭目吧，我不能收你。");
}

string do_ask1()
{
  object me=this_player();

  // 已經取得惡人證了
  if (me->query("quests/badman_license")) {
    if (!present("badman license", me)) {
	if (new(BAD_OBJ"license")->move(me))
	  return "噫? 你惡人證遺失啦? 我再補一張給你好了。\n";
	else
	  return "喔, sorry, 惡人證目前短缺中，等等再來。\n";
    }
    if (random(2))
	return "你身上的惡人證是入谷的證明，想過去可以過去，我不攔你。\n";
    else
	return "你已經有惡人證了，正是我的同伴，歡迎進入惡人谷。\n";
  }
  else if (me->query_temp("quests/badman_license") != 0)
    switch (random(5)) {
	case 0:
	  return "還不快去找惡人證，呆在這兒幹嘛?\n";
	  break;
	case 1:
	  return "光問我惡人證是沒用的，心動不如馬上行動。\n";
	  break;
	case 2:
	  return "當然得去谷外尋找惡人證了。\n";
	  break;
	default:
	  return "只有真正心地邪惡的人才有資格拿到惡人證。\n";
	  break;
    }
  else {
    me->set_temp("quests/badman_license", 1);
    if (random(2))
	return "如果你能拿燕南天的屍體來，我就發給你一張惡人證。\n";
    else
	return "想從我手中拿到惡人證，除非提燕南天的屍體來換吧。\n";
  }
}

string do_ask2()
{
  switch (random(5)) {
    case 0:
	return "啊! 他真是令人可敬可畏的人啊。\n";
	break;
    case 1:
	return "要不是他，我們也不必躲到惡人谷來了。\n";
	break;
    case 2:
	return "他正是另黑白兩道都配服的人，也正是惡人谷的死仇大敵。\n";
	break;
    case 3:
	return "他的劍術已經達到心劍合一的地步了。\n";
	break;
    default:
	return "唉，別提他了，你一提他我就頭疼。\n";
  }
}

// 要帶燕南天的屍體來
// 因為還要在裡面救活哩
int accept_object(object who, object ob)
{      
  string name, str;

  if (ob->query("name") == "腐爛的屍體") {
    tell_object (who, "司馬煙冷冷的說道: 屍體都爛成這樣了，誰知道你拿的"+
			"是哪隻阿貓阿狗的屍體啊？\n");
    command("give "+who->query("id")+" "+ob->query("id"));
    return 1;
  }

  if (ob->query("name") != "燕南天的屍體") {
    if (random(2))
	tell_object (who, "司馬煙生氣的說道: 叫你拿個燕南天的屍體，"+
				"你給我的這是什麼跟什麼啊。\n");
    else
	tell_object (who, "司馬煙恨恨的道: 不拿燕南天的屍體來有個屁用啊。\n");
    command("give "+who->query("id")+" "+ob->query("id"));
    return 1;
  }

  if (who->query_temp("quests/badman_license")!=6) {
    if (random(2))
	tell_object (who, "司馬煙很高興的說道: 噫? 要送我燕南天的屍體? "+
		     "這下我可以去邀功\了，真多謝你了。\n");
    else
	tell_object (who, "司馬煙很高興的說道: 謝謝你這麼努力幫我殺死燕南天，"+
	  	     "可惜沒什麼好賞你。\n");
    destruct(ob);
    return 1;
  }

  if (new(BAD_OBJ"license")->move(who)) {
    if (random(2))
	tell_object (who, "司馬煙看了看屍體說: 沒錯，這是燕南天的屍體，"+
				"就發給你一張惡人證吧。\n");
    else
	tell_object (who,
		"司馬煙看了看屍體說: 看在你辛苦解決惡人谷的大患的面上，" +
		"就發給你一張惡人證吧。\n");
    name = who->query("name");
    str = name[0..1];
    tell_object (who,
		"司馬煙恭敬的對你說: "+str+"大俠，真想不到您能幹掉燕南天，"+
		"谷主已經在等您了，請進。\n");
    who->set("quests/badman_license",1);
    who->delete_temp("quests/badman_license");
  }
  else {
	write ("司馬煙嘆了口氣說道: 目前物資缺乏，你只好等以後再來了。\n");
	who->delete_temp("quests/badman_license");
  }
  destruct (ob);
  return 1;
}

int accept_fight(object who)
{
  return notify_fail("司馬煙瞪了你一眼說: 哼，老子沒空理你，少煩我！\n");
}

int accept_kill(object who)
{
  object me;
  me=this_object();
  if( me->is_fighting() )
	return 1;
  command("shout 好小子，竟敢硬闖惡人谷，我看你是不要命了。");
  command("shout 兄弟們，給我宰了"+who->query("name")+"這個兔崽子！");
  return 1;
}

/*
void die()
{
  CHANNEL_D->do_channel(this_object(), "mud", HIY"\n惡人谷被人入侵了！！"NOR);
  ::die();
}
*/
