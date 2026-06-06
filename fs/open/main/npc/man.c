//增加方便盲人朋友的便利inquiry 因此其他人依舊照原流程 by blazakira 2011/3/19
//新增盲人朋友的新角色shoot by blazakira 2011/6/12
//新增盲人朋友的新角色kived by blazakira 2011/8/5
//新增盲人朋友的新角色rokudo by blazakira 2011/8/5
//新增死亡訊息 by blazakira 2011/10/15

#include <ansi.h>
#include "/open/open.h"

inherit NPC;

string do_ask ();
string do_ask2();

void create()
{
  seteuid(getuid());
  set_name("太極長老", ({ "old man","man" }) );
  set("nickname","一代宗師");
  set("gender", "男性" );
  set("age", 99);
  set("no_kill",1);
  set("no_plan_follow",1);
  set_temp("roared",1);
  set("no_get",1);
  set("no_fight",1);
  set_weight (500);
  set("long", @LONG
    他好像有一些煩腦，如果你能解決他的煩腦(question)，應該可以獲得不少好處。
LONG);

  set("chat_chance", 80);
  set("chat_msg", ({
    (:random_move:),
    HIC + "太極長老說道：這個問題(question)還真是困難啊。\n" + NOR,
    HIC + "太極長老說道：怎麼看了哪麼久的圖，還是看不懂這個圖在畫什麼。\n" + NOR
  }) );
  set("inquiry", ([
    "question":   (:do_ask:),
    "welcomefs":   (:do_ask2:),
  ]) );
  set("no_kill",1);
  set("no_fight",1);
  set("score",100000000);
  set("combat_exp",1000000);
  set_temp("roared",1);
  set("mystery",1);
  set("ann_die",1);
  setup();
  carry_object(MAIN_OBJ"sword")->wield();
}
void heart_beat()
{
  if(!environment()) return;
  if(random(10) == 0)
  {
    command("open door");
    random_move();
    command("open door");
  }
  ::heart_beat();
}

void init()
{
  set_heart_beat(1);
  add_action("do_ans","ans");
  add_action("do_ans2","answer");
}

void kill_ob(object obj)
{
  if(!userp(obj)) return ;
  ::kill_ob(obj);
}

string do_ask ()
{
  object me=this_player();
  string str="";
  string *word ;
  word = "/adm/daemons/word1.c"->get_word(5);
  me->set_temp("ask_word",word[0]);
  set("random_move",1000);
  tell_object(me,HIC + "長老翻開他的書本，上面畫著：\n"+word[2]+"\n(註：回答全為小寫)\n");
  return "你能幫我看看上面的圖寫什麼嘛(ans)？";
}

string do_ask2() //這是為了盲人朋友所額外設計的動作 未經報備的就先冰起來 踢出去吧 然後砍檔 by blazakira
{ //全程使用tell_object 來指定對象
  object me=this_player(),ob=this_object();
  string name1,name2;
  name1=me->query("name");
  name2=ob->query("name"); //一般玩家 我都提示你這麼清楚了(加括號 再補顏色) 你還犯錯 嘖嘖（聳肩
  tell_object(me,name2+"呵呵說道：是你呀，"+name1+"，上面有交代要我便宜行事，因此得免去一些程序。\n"+
    name2+"從懷裡拿出紙跟筆來迅速地在上面寫" + HIY + "(log)" + NOR + "些什麼。\n\n"+
    name2+"嚴肅說道：在此我要慎重地提醒你，這是在你這角色報備後才能使用的簡易流程，\n"+
    "                  如果沒問題那就請繼續下個動作(answer yes)。\n");
  if( me->query("id")== "kiven" || me->query("id")== "cureman" || me->query("id")== "kyoya" ||
      me->query("id")== "mukuro" || me->query("id")== "shoot" || me->query("id")== "kived" ||
      me->query("id")== "rokudo")
    me->set_temp("welcome_to_fs","not_robot");
  else
    me->set_temp("welcome_to_fs","ng");
  return ""; //不使用 所以空著
}

int do_ans2(string arg) //只要上線之後 問過上面的問題一次後 都可以直接回答yes 跳過上面的問題
{
  object me=this_player(),ob=this_object();
  if(!arg && arg != "yes") return 0;
  log_file("太極內力",sprintf("%s(%s)於%s這時間向%s祈求太極內力。(%s)\n",me->query("name"),me->query("id"),
    ctime(time()),ob->query("name"),query_ip_name(me) ));
  if( me->query_temp("welcome_to_fs") =="ng") {
    tell_object(me,"" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "太極長老說道﹕你不合規定免流程的名單，掰掰～\n" + NOR);
    me->do_command( "sleep 1 0 0 7" ); //冰起來
  }
  else if( me->query_temp("welcome_to_fs") =="not_robot") {
    tell_object(me,"" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "太極長老說道﹕嗯嗯，盡情享受這段時間吧。\n" + NOR);
    tell_object(me,"" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "太極長老說道﹕讓我傳一些功\力給你，二小時之內，你在練功\時，會覺得獲得更多。\n" + NOR);
    me->delete_temp("ask_word");
    me->set_temp("not_robot",time() + 60*120);
  }
  return 1;
}

int do_ans(string arg)
{
  string i ;
  object me=this_player();
  if(!arg) return notify_fail("請加上英文字母來作為回答，而且全為小寫\n");
  i = arg;
  if(!me->query_temp("ask_word")) return notify_fail("你想幹什麼？\n");
  if(i != me->query_temp("ask_word"))
  {
    command("say 我看好像不是這樣呢！");
    return 1;
  }
  else
  {
    command("say 啊，真的是這樣");
    command("say 讓我傳一些功\力給你，二小時之內，你在練功\時，會覺得獲得更多。");
    me->delete_temp("ask_word");
    me->set_temp("not_robot",time() + 60*120);
    return 1;
  }
}

// 不打算 return home
int return_home(object home){
  return 0;
}

