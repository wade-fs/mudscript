//q1_trainee.c 基本上 三位挑水和尚的檔案都相同 只是name不同而已 quest 目的一樣 by blazakira 2010/11/24

#include <ansi.h>
#include "bonze.c"
inherit NPC;
string ask_job();
string ask_dispute();
string ask_bucket();
void create()
{
  object obj;
  set_name("阿二",({"janitor two","two"}));
  set("title","少林雜役弟子");
  set("long","他為了在學習少林武功前打下深厚的基礎而每天挑水砍柴。\n");
  set("gender","男性");
  set("combat_exp",80000);
  set("attitude","peaceful");
  set("age",16);
  set("class","bonze");
  set_skill("unarmed",35);
  set_skill("dodge",20);
  set_skill("parry",30);
  set("chat_chance", 80);
  set("chat_msg", ({
    (: random_move :),
    (: random_move :),
    (: random_move :),
    "阿二說道﹕怎麼會這樣呢，以前只有我在挑水的時候還不覺得複雜，怎人一多就…\n",
	"阿二說道﹕寺裡的水快用完了，我應該一個人去就好，雖然辛苦了點，唉～\n",
	"阿二說道﹕我是不是該獨自去挑水呢…\n",
	"阿二說道﹕一根扁擔兩個頭，只要他們其中一位讓一下就不會這麼麻煩了，唉～\n",
	"阿二說道﹕一根扁擔兩個頭，他們人太好了所以才會跟我爭挑水的工作，唉～\n",
	"阿二說道﹕唉～為什麼他們都不讓步呀…\n"}));
  set("inquiry", ([
	"心結"      : (: ask_dispute :),
	"苦惱"      : (: ask_dispute :),
	"糾紛"      : (: ask_dispute :),
	"砍柴"      : "少林後山林木繁盛但也得留薪火以待來者才行。\n",
	"挑水"      : (: ask_job :),
    ]));
  set_temp("quests/bonze/stop",1);
  setup();
  set_temp("apply/attack", 4);
  set_temp("apply/damage", 1);
  set_temp("apply/armor", 3);
  obj=new(BONZE_OBJ"bucket.c");
  obj->set("no_steal",1);
  obj->set("no_get",1);
  obj->move(this_object());
  add_money("coin",20);
}

void init()
{
  object ob=this_object();
  if ( ob->query("quests/bonze/water/stop") ) {
    ob->set("nickname","勤奮挑水的");
  }
  add_action("do_nod","nod");
  add_action("do_ok","ok");
  add_action("do_shake","shake");
  set_heart_beat(1);
  ::init();
}

void greeting(object who)
{
  object ob=this_object();
  if ( who->query_temp("quests/bonze/water/method1")==1 ) {
    write(HIY + "阿二看見你時，緊張地快說不出話來﹕施…主，我、我…這就去…挑、挑水。\n只見他慌慌張張地拿起一旁的水桶後迅速離開你眼前。\n" + NOR);
    command("flee "+who->query("id"));
    destruct(ob);
  }
}

int accept_kill(object who)
{
  object ob;
  ob=this_object();
  if( ob->is_fighting() )
    return 1;
  command("shout "+who->query("name")+"施主的心腸怎麼這麼狠毒！阿彌陀佛——");
  return 1;
}

int accept_fight(object who)
{
  message_vision("阿二對$N搖搖手指說﹕$N一邊玩去，和尚我快下定決心去挑水了。\n",who);
  return notify_fail("");
}

string ask_dispute()
{
  object me = this_player();
  if ( !me->query("quests/bonze/water/start") )
    return "施主你著相了，吾輩少林弟子必須遵循不瞋、不貪、不癡等戒律。";
  me->set("quests/bonze/water/start",2);
  return "施主有心了，我們師兄弟三人雖然沒有真正的吵起來，但是也相差不遠，起因是挑水的問題。\n一根扁擔兩個頭，因此我們僵持不下，這才導致無人挑水，罪過罪過。";
}

string ask_job()
{
  object me = this_player();
  if ( me->query("quests/bonze/water/start") <2 )
    return "嗯！這是一件不簡單的工作，藉以鍛鍊體魄與堅定心念才能秉持本心。";
  if ( this_object()->query("quests/bonze/water/stop") )
    return "阿彌陀佛，施主有事嗎？";
  if ( me->query_temp("quests/bonze/water/method1") || me->query_temp("quests/bonze/water/method2"))
    return "不知道有誰能夠幫忙或者出點主意也好？";
  me->set_temp("quests/bonze/water/method2",1);
  me->set_temp("quests/bonze/water/times",0);
  return "不知道該怎麼解決這件事，還是說施主願意指點或者能提供什麼幫助？";
}

int do_nod(string str)
{
  object ob = this_object() , me = this_player();
  object obj;
  if ( me->query("quests/bonze/water/finish")==1 ) return 0;
  if ( !me->query_temp("quests/bonze/water/method2") ) return 0;
  if ( me->query_temp("quests/bonze/water/method1") >0 ) return 0;
  if ( me->query_temp("quests/bonze/water/method2") >1 ) return 0;
  command("say 這樣也好，那麼…就煩勞施主了，阿彌陀佛。");
  command("bow "+me->query("id"));
  if( !present("bucket",me) ) {
    obj=new(BONZE_OBJ"bucket.c");
    obj->move( me );
    message_vision("$n拿起身旁的水桶交給了$N。\n",me,ob);
  }
  else {
    command("say 喔喔～既然施主身上已經有了水桶，和尚我就不多此一舉了，阿彌陀佛。");
  }
  me->set_temp("quests/bonze/water/method2",2);
  return 1;
}

int do_shake(string str)
{
  object ob = this_object() , me = this_player();
  if ( !me->query_temp("quests/bonze/water/method2") ) return 0; //如果沒有開始解謎的動作就不回應
  if ( me->query_temp("quests/bonze/water/method1") >0 ) return 0; //如果進入解謎方法一時就不回應 並在init裡刪除本npc //此步驟為避免萬一 因為greeting()會先判斷
  if ( me->query_temp("quests/bonze/water/method2") >1 ) return 0; //只有當等於1時才會繼續下面的判斷
  command("say 嗯嗯，既然施主覺得困擾的話，那麼請稍候有空閒時再過來看看好了，阿彌陀佛。");
  command("smile "+me->query("id"));
  me->set("quests/bonze/water/start",0);
  me->set_temp("quests/bonze/water/method2",0);
  return 1;
}

void die()
{
  object winner=query_temp("last_damage_from");
  object ob=this_object();
  if ( !ob->query("quests/bonze/water/stop") && winner->query("quests/bonze/water/start") >1 ) {
    winner->set_temp("quests/bonze/water/method1",1);
    winner->set_temp("quests/bonze/water/method2",0);
    winner->set_temp("quests/bonze/water/times",0);
  }
  else {
    winner->set_temp("quests/bonze/water/method2",0);
    winner->set_temp("quests/bonze/water/times",0);
    winner->set_temp("quests/bonze/water/start",0);
  }
  if( present("bucket",ob) )
  {
    object obj = present("bucket",ob);
    obj->move(BONZE_ROOM"k08");
    environment(obj)->set("no_reset",1);
    environment(obj)->start();
    environment(obj)->add_temp("quests/bonze/water/ppl/method1/"+winner->query("id"),1);
    destruct(obj);

    foreach( object ob2 in children(BONZE_NPC"q1_trainee.c") ) {
      if(clonep(ob2)) {
        ob2->set("quests/bonze/water/stop",1);
        ob2->set("quests/bonze/water/time",time());
      }
    }
    foreach( object ob2 in children(BONZE_NPC"q1_trainee2.c") ) {
      if(clonep(ob2)) {
        ob2->set("quests/bonze/water/stop",1);
        ob2->set("quests/bonze/water/time",time());
      }
    }
    foreach( object ob2 in children(BONZE_NPC"q1_trainee3.c") ) {
      if(clonep(ob2)) {
        ob2->set("quests/bonze/water/stop",1);
        ob2->set("quests/bonze/water/time",time());
      }
    }
    foreach( object ob2 in children(FQ_NPC"k_monk3.c") ) {
      if(clonep(ob2)) {
        ob2->set("quests/bonze/water/stop",1);
        ob2->set("quests/bonze/water/time",time());
      }
    }
  }
  ::die();
}
