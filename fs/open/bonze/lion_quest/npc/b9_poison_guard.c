#include <ansi.h>
#include "/open/open.h"
inherit NPC;

string poison();
int bout=0; //給予本npc停留在該房間時間設定的變數

void create()
{
  set_name("流浪漢",({"ranger","r"}) );
  set("long","你發覺此人正偷偷地窺視著聯盟裡的成員並不斷地暗暗打量著什麼。
微風輕拂，你聞到他的身上有著玫瑰的異味，你懷疑他是某個門派的核心成員。\n");
  set("gender","男性");
  set("class","poisoner");
  set("combat_exp",7310000);
  set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","aggressive"); //主動攻擊玩家
  set("age",22);
//  set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
  set("poison",100000);
  set("env/cure_poison","dark");
  set("str", 40);
  set("cor", 26);
  set("cps", 15);
  set("per", 21);
  set("int", 37);
  set("kar", random(7)+10);
  set("force",10000);
  set("max_force",10000);
  set("bellicosity",1500);
//  set("kee",39400); //不另設置 kee是因為 exp+force 似乎有加成超過max_kee
  set("max_kee",39400);
  set_skill("ming-snake",100);
  set_skill("whip",100);
  map_skill("whip","ming-snake");
  set_skill("parry",90);
  map_skill("parry","ming-snake");
  set_skill("force",70);
  set_skill("poisonforce",75);
  map_skill("force","poisonforce");
  set_skill("poison",76);
  set_skill("coldpoison",85);
  map_skill("poison","coldpoison");
  set_skill("nine-steps",100);
  set_skill("dodge",130);
  map_skill("dodge","nine-steps");
  set_skill("move",100);
  map_skill("move","nine-steps");
  set("functions/suck/level",100);
//  set("functions/firefinger/level",100);
//  set("functions/five/level",100);
  set_temp("apply/armor",70); //+防的指令之一
  set_temp("apply/defense",10); //+防的指令之一
  set("force_factor",17);
  set("chat_chance_combat",75);
  set("chat_msg_combat",({
    (: poison :),
    (: perform_action("poison.faint") :),
    (: perform_action("nine-steps.snake-steps") :),
  }));
  set("chat_chance",random(30)+15);
  set("chat_msg",({
    (: random_move :), //單純隨機移動
  }));
  set("family/family_name","冥蠱魔教");
  set("no_learn",1); //避免意外 所以設有禁止玩家學習技能
  delete("family/privs"); //刪除rb 5min保護 因create_family() 會自動產生 ("family/privs") 這是給門派首領使用的新手保護設定
  set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                    //為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域
  setup();
  carry_object("/open/doctor/pill/rose_pill.c")->set_amount(1);
  carry_object("/open/doctor/pill/dark_pill.c")->set_amount(1);
  carry_object("/obj/poison/faint_poison")->set_amount(20);
  carry_object("/obj/poison/dark_poison.c")->set_amount(15);
  carry_object("/obj/poison/rose_poison.c")->set_amount(10);
  carry_object("/open/poison/obj/ewhip.c")->wield();
  carry_object("/open/poison/obj/armband.c")->wear();
  carry_object("/open/poison/obj/boots.c")->wear();
  carry_object("/open/poison/obj/cloak.c")->wear();
  carry_object("/open/poison/obj/cape.c")->wear();
  carry_object("/open/gsword/obj/ring-1");
  add_money("gold",random(3));
}

int accept_kill(object who) 
{
  command("say 看我自創的天～女～散～花～～");
  command("cmd throw poison 1 to "+who->query("id"));
  command("cmd throw poison 2 to "+who->query("id"));
  command("cmd throw poison 3 to "+who->query("id"));
  command("cmd throw poison 4 to "+who->query("id"));
  command("cmd throw poison 5 to "+who->query("id"));
  command("wear all");
//應該不論kill or fight 只要設定成一個 其他圍攻的npc 統統下fight好了 這樣比較容易
  who->set_temp("quests/bonze/fight", 1 ); //在玩家身上紀錄
  return 1;
}

int accept_fight(object who)
{
  if(this_object()->is_fighting())
    return notify_fail("你沒看到我正在忙嗎?\n");
  return 1;
}

string poison()
{
  command("perform poison.faint");
  return "\n";
}

void greeting(object me)
{
  if(me->query("family/family_name")=="冥蠱魔教")
  { 
    command("smile "+me->query("id"));
  }
  else if(me->query("family/family_name")=="金刀門")
  {
    command("say 口亨！金刀門來的！找死！！");
    command("cmd throw poison 1 to "+me->query("id"));
    command("cmd throw poison 2 to "+me->query("id"));
    command("cmd throw poison 3 to "+me->query("id"));
//    kill_ob(me);
  }
  else
  {
    command("yawn "+me->query("id"));
  }
}

//使用全域變數 來延長mob存在的時間
//魚缸@台北  - 說 (上午 12:10):
//自已加一個全域變數
//魚缸@台北  - 說 (上午 12:10):
//然後沒 fighting 的話就 +1
//魚缸@台北  - 說 (上午 12:11):
//加到超過一定秒數就destruct 掉

void init()
{
  set_heart_beat(1); //設定為一次的心跳
  ::init(); //只設定本行時與雪蒼liu 相同 會執行 非戰鬥時 回靈力的判斷 不如說 非戰鬥時 一樣會執行指令:p
}

void heart_beat()
{
//參考郭襄與趙高的逃跑模式 //以下得在使用前先定義
  object me=this_object(),env;
  mapping exit; 
  string *exit_name;
  int i,maxkee; //i為房間出口變數的存量 maxkee為紀錄玩家max_kee的存量
  env = environment(me);
  if(!me || !env) return;
  maxkee=me->query("max_kee",1);
  if( (me->query("kee") < me->query("max_kee")*0.3) && (random(100) < 30) ) //提高逃跑機率就減少下行逃跑次數 by blazakira
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
  if (is_fighting() && me->query("kee") < maxkee*0.3 && me->query_temp("unconcious") != 1 && (random(100) < 20))
  {
    tell_room(environment(), name()+"面露獰色地吞下一粒大還丹。\n");
//補血不能有小數 所以用(int)與非小數的方式來取整數 且括號後面的計算式以便debug
    me->receive_curing("kee",(int)(maxkee/100*2));
    me->receive_heal("kee",(int)(maxkee/100*4));
    me->receive_curing("sen",(int)(maxkee/100*1));
    me->receive_heal("sen",(int)(maxkee/100*2));
    me->receive_curing("gin",(int)(maxkee/100*1));
    me->receive_heal("gin",(int)(maxkee/100*2));
  }

  bout++; //為計算時間的變數累計+1 目前設定為非戰鬥時才開始計算
  me->set_temp("count_down",bout);
  ::heart_beat();
}

int heal_up()
{
  if (is_fighting() && this_object()->query_temp("count_down") > 30) //如果在戰鬥中 則減少秒數 避免玩家逃跑回氣時 該npc瞬間消失
  bout=bout-10; //為計算時間的變數累計

  if (!is_fighting() && this_object()->query_temp("count_down") > 40) //心跳一次 1:1.5(秒)==>1.5x40=1min, 15min=1.5x40x15=900 //暫定為解迷mob 所以 縮短時間為40
  { //心跳一次 1:1.5(秒)==>1.5x40=1min, 15min=1.5x40x15=900
    message_vision (HIY"$N發覺不對勁，於是轉身而逝，消失在陰影裡！\n"NOR, this_object ());
    destruct(this_object());
    return 1;
  } //此括號仍為判斷是否在戰鬥中的if下引號
  return ::heal_up();
}
