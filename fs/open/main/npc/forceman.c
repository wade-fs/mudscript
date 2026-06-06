//因為會被swordsman砍 所以增加逃跑功能 by blazakira 2010/10/2
//增加sw家族的判定 避免被砍 by blazakira 2010/12/22
//排版與增加死亡訊息 by blazakira 2011/10/15

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

string do_ask();

void create()
{
  seteuid(getuid());
  set_name("掃地老頭", ({ "clear man","man" }) );
  set("gender", "男性" );
  set("age", 99);
  set("no_kill",1);
  set("no_fight",1);
  set_temp("roared", 1 ); //會被swordsman roar 所以補上 by blazakira
  set("mystery",1); //加入神秘家族吧 不然一直被砍很麻煩 by blazakira
  set_weight (500);
  set("long", @LONG
    傳言中，越不起眼的老頭，越有高深的功力。
也許他可以幫你打通你身上「內力」的極限。
LONG);
  set("chat_chance", 80);
  set("chat_msg", ({
    (:random_move:),
    HIC"掃地老頭拿著掃把一直掃地。\n"NOR
  }) );
  set("inquiry", ([
    "內力": (:do_ask:),
  ]) );
  set("combat_exp",1000000000);
  set_temp("pk_fight",1);
  set("ann_die",1);
  setup();
  carry_object(MAIN_OBJ"sword")->wield();
}

string do_ask ()
{
  object me=this_player();
  string str="";
  string *word ;
  if(query_temp("add_force"))
  {
    return "我的內力不足了，可能要請你等等。";
  }

  word = "/adm/daemons/word1.c"->get_word(5);
  me->set_temp("ask_word",word[0]);
  set("random_move",1000);
  tell_object(me,HIC "老頭翻開他的書本，上面畫著：\n"+word[2]+"\n(註：回答全為小寫)\n");
  return "你能幫我看看上面的圖寫什麼嘛(ans)？";
}

void init()
{
  // 這樣才會不斷的走。
  set_heart_beat(1); 
  add_action("do_ans","ans");
}

void reset()
{
  delete_temp("add_force");
}

// 不打算 return home
int return_home(object home)
{
  return 0;
}

int do_ans(string arg)
{
  string i;
  object me=this_player();
  if(!arg) return notify_fail("請加上英文字母來作為回答，而且全為小寫。\n");
  if(query_temp("add_force"))
  {
    return notify_fail("我的內力不足了，可能要請你等等。");
  }

  i = arg;
  if(!me->query_temp("ask_word")) return notify_fail("你想幹什麼？\n");
  if(i != me->query_temp("ask_word"))
  {
    command("say 我看好像不是這樣呢！");
    return 1;
  }
  else
  {
    command("say 啊，真的是這樣！");
    command("say 讓我傳一些功\力給你，二小時之內，你在練功\時，會覺得獲得更多。");
    me->delete_temp("ask_word");
    me->set_temp("not_robot",time() + 60*120);
    set_temp("add_force",1);
    return 1;
  }
}

void heart_beat()
{
//參考郭襄與趙高的逃跑模式 //以下得在使用前先定義
  object me=this_object(),env;
  mapping exit;
  string *exit_name;
  int i,maxkee; //i為房間出口變數的存量 maxkee為紀錄玩家max_kee的存量
  maxkee=me->query("max_kee",1);
  env = environment(me);
  if( me->is_fighting() && (me->query("kee") < me->query("max_kee")) && (random(100) > 30) ) //只要被打就逃跑
  {
    exit = env->query("exits");
    exit_name = keys(exit);
    i = random(sizeof(exit_name));
    command(exit_name[i]);
    i = random(sizeof(exit_name));
    command(exit_name[i]);
  }

//自己補血的設定
//將影響的機率分別計算 戰鬥中與 非戰鬥中 且不能暈倒 暈倒還自補 那就搞笑哩XD
//因為有仙雲之氣 所以調低自補機率30->10
  if (me->query("kee") < maxkee*0.50 && me->query_temp("unconcious") != 1 && (random(100) < 30))
  {
    if (is_fighting()) {
//補血不能有小數 所以用(int)與非小數的方式來取整數 且括號後面的計算式以便debug
      me->receive_curing("kee",(int)(maxkee/100*3));
      me->receive_heal("kee",(int)(maxkee/100*7));
      me->receive_curing("sen",(int)(maxkee/100*2));
      me->receive_heal("sen",(int)(maxkee/100*3));
      me->receive_curing("gin",(int)(maxkee/100*2));
      me->receive_heal("gin",(int)(maxkee/100*3));
      tell_room(environment(), name()+"吃下一粒百花清心露"HIC"(強效)。\n"NOR);}
    else { //非戰鬥時
      if( query("kee") < query("eff_kee") && (random(100) < 40) ) {
        command("exert recover"); }
      if( query("eff_kee") < query("max_kee") && (random(100) < 50) ) {
        command("exert heal"); }
      if( query("eff_kee") < query("max_kee") && (random(100) < 10) ) {
        command("eat flower pill"); } //解毒 解狀態
    }
  }

  ::heart_beat(); //心跳函數的結尾
}
