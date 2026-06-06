#include <ansi.h>
inherit NPC;
inherit SSERVER;

int bout=0; //給予本npc停留在該房間時間設定的變數

void create()
{
  set_name("殿閣大學士",({"temple bookman","temple","bookman","b"}));
  set("long","大學士一職乃唐中宗時首創，原職為協助皇帝批閱\奏章，起草詔書等。
與段家理念不合，因此投奔到儒門憑藉著自身實力進而取得一席之地。\n");
  set("nickname",HIC + "滅" + HIY + "獅" + NOR + "聯盟");
  set("gender","男性");
  set("class","scholar");
  set("combat_exp",6180000);
  set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","aggressive"); //主動攻擊玩家
  set("age",55);
//  set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
//練功型的mob 暫時不考慮太多的特攻
//行雲流水筆法 增加連擊功能，放在兩個post_action(speed1跟speed2)上，
//  a.speed1最基本使用條件：解過fire-king。
//  b.speed2最基本使用條件：解過儒尊。
  set("plan-quest/ko-fire-king",1);
  set("mark/sixgod-plan",1); //解過儒尊『六韜奇略』
  set("kar", random(7)+26);
  set("s_kee",1000);
  set("max_s_kee",1000); //由於仙雲之氣回復量為此值*2 所以若有另外自補的情況 則本數值不可太高
  set("sec_kee","god");
  set("force",8000);
  set("max_force",8000);
//  set("kee",35700); //不另設置 kee是因為 exp+force 似乎有加成超過max_kee
  set("max_kee",35700);
//  set_skill("cure",60);
//  set_skill("unarmed",20);
  set_skill("literate",70);
  set_skill("knowpen",60);
  set_skill("stabber",80);
  map_skill("stabber","knowpen");
  set_skill("parry",70);
  map_skill("parry","knowpen");
  set_skill("force",40);
  set_skill("poetforce",40);
  map_skill("force","poetforce");
  set_skill("winter-steps",50);
  set_skill("dodge",40);
  map_skill("dodge","winter-steps");
  set_skill("move",40);
  map_skill("move","winter-steps");
  set_skill("plan",70);
  set_skill("god-plan",60);
  map_skill("plan","god-plan");
  set("functions/movedown/level",10);
  set("functions/finger/level",10);
  set_temp("apply/armor",40); //+防的指令之一
  set_temp("apply/defense",10); //+防的指令之一
  set("force_factor",18);
  set("chat_chance_combat", 50);
  set("chat_msg_combat",({
    (: perform_action,"stabber.movedown" :),
    (: perform_action,"stabber.finger" :),
    (: perform_action,"plan.lock-link" :)
  }));
  set("chat_chance",random(30)+15);
  set("chat_msg",({
    (: random_move :), //單純隨機移動
  }));
  create_family("儒門",16,"大學士"); //設定為 與master_sue聖賢書 同一代的人物 因為職稱的關係
                                     //第16代以上為長老級別(暫定)
//  set("family/family_name","儒門");
  set("no_learn",1); //避免意外 所以設有禁止玩家學習技能
  delete("family/privs"); //刪除rb 5min保護 因create_family() 會自動產生 ("family/privs") 這是給門派首領使用的新手保護設定
  set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                    //為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域
  setup();
  carry_object("/open/scholar/obj/silver-pen.c")->wield();
  carry_object("/open/scholar/obj/s_cloth.c")->wear();
  carry_object("/open/scholar/obj/s_leggings.c")->wear();
  carry_object("/open/scholar/obj/s_neck.c")->wear();
  carry_object("/open/ping/obj/ring-2");
  add_money("gold",random(15));
}

void init()
{
  set_heart_beat(1); //設定為一次的心跳
  ::init(); //只設定本行時與雪蒼liu 相同 會執行 非戰鬥時 回靈力的判斷 不如說 非戰鬥時 一樣會執行指令:p

//測試是否呼叫mob時會參與圍攻的函數call 
//  remove_call_out("greeting");
  call_out("greeting", 1, this_player());
}
//點子 或許有些門派可以考慮主動follow某些門派 甚至組隊～～
//可考慮 1~2個門派會有追殺的情形 這也是特色 :p

void greeting()
{
  object ppl=this_player(),ob=this_object();
  if(!userp(ppl)) return; //直接對於非玩家的角色忽略 應可避免殺手呼叫影武者 天道的招喚術這類的情況？
//進入該房間時(重生時 被呼叫出來時)此時為非戰鬥狀態(因為推測有可能是逃跑後 可加上限制為某個hp比例以上
//藉以讓擁有回血的npc恢復) 發現玩家在戰鬥中 且身上有攻擊的mark 就攻擊她
  if (!ob->is_fighting() && ppl->query_temp("quests/bonze/fight") == 1
      && ppl->is_fighting() && (ob->query("kee") > ob->query("max_kee")*0.3))
  {
    message_vision (HIY + "$N大喊：無事生非者，殺無赦！\n" + NOR, ob);
    fight_ob(ppl);
//    command("kill "+ppl->query("id"));
  }

//沒有報告者有40%的機率會被主動攻擊
//因為是主動攻擊 所以強化npc數值
  if( !ppl->query_temp("有向瀧山護法報告") && !ppl->query_temp("quests/bonze/mob") ) //判斷前者針對玩家 後者針對npc
  {
    if ( random(100) < 40)
    {
      command("say "+ppl->query("name")+"鬼鬼祟祟的想做什麼！盟主有令，意圖不明者，殺～無～赦！");
      ppl->set_temp("quests/bonze/fight", 1 ); //圍攻
      if (!ob->query_temp("quests/bonze/power_up") && query_temp("unconcious") != 1) //昏倒了就算了
      { //因為每種npc 所使用的特攻不同 所以乾脆統一加血作為威力提昇比較省事 by blazakira
        ob->add("force",20000+random(10000));
        ob->add("kee",40000+random(25000)); //逃跑跟回血都影響所以補上
        ob->add("eff_kee",40000+random(25000)); //會影響到逃跑機率 所以補上
        ob->add("max_kee",40000+random(25000)); //會影響到回血功能 所以補上
        ob->add("gin",20000+random(15000));
        ob->add("eff_gin",20000+random(15000));
        ob->add("max_gin",20000+random(15000));
        ob->add("sen",20000+random(15000));
        ob->add("eff_sen",20000+random(15000));
        ob->add("max_sen",20000+random(15000));
        ob->add("force_factor",10+random(10));
        ob->set_temp("quests/bonze/power_up",1);
        message_vision (HIR + "$n眼尖發現了$N拿出一罐秘藥並喝了下去。\n" + NOR, ob, ppl);
      }
      message_vision (HIR + "$n看出$N的身上散發著不斷高漲的殺氣。\n" + NOR, ob, ppl);
      fight_ob(ppl);
    }
    else {
      command("hehe "+ppl->query("id"));
    }
    remove_call_out("greeting");
  }
  else if (ppl->query_temp("quests/bonze/mob") ==1) { remove_call_out("greeting"); } //將是否為npc的判斷獨立出來
  else if (ppl->query_temp("quests/bonze/greet") < 3) { //有report之後的動作 //加上打招呼的累計判斷
    if (ob->query("class") == ppl->query("class"))
    {
      command("smile "+ppl->query("id"));
      command("say "+ppl->query("name")+"你記著，我們是一個愛好和平的高尚門派喔。");
    }
    else {
      command("hi "+ppl->query("id"));
      command("say "+ppl->query("name")+"走在路上要小心看路喔。");
    }
    ppl->add_temp("quests/bonze/greet",1); //打招呼用的次數
    remove_call_out("greeting");
  }
}

int accept_fight(object who)
{
  command("say 老身年紀大了，不太適合激烈的活動……咳咳\n");
  command("wear ice_ring");
  command("cmd god_kee");
  fight_ob(who);
  command("perform plan.fire");
//應該不論kill or fight 只要設定成一個 其他圍攻的npc 統統下fight好了 這樣比較容易
  who->set_temp("quests/bonze/fight", 1 ); //在玩家身上紀錄圍攻用途的mark
  return 1;
}

int accept_kill(object who)
{
  command("say 老身就來領教閣下的高招，看招！\n");
  command("wear ice_ring");
  command("cmd god_kee");
//  kill_ob(who);
  command("perform plan.fire");
  who->set_temp("quests/bonze/fight", 1 );
  return 1;
}

void heart_beat()
{
//參考郭襄與趙高的逃跑模式 //以下得在使用前先定義
  object me=this_object(),env;
  mapping exit; 
  string *exit_name;
  int i,maxkee; //i為房間出口變數的存量 maxkee為紀錄npc max_kee的存量
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
//因為有仙雲之氣 所以調低自補機率30->10
  if (me->query("kee") < maxkee*0.45 && me->query_temp("unconcious") != 1 && (random(100) < 10))
  {
//換湯不換藥的戰鬥與非戰鬥的表示方式 旨在迷惑玩家而已 by blazakira
//使用過即可刪除的點子 可考慮 楊氏續命丹(本區後勤藥店名稱 或是生生造化丹（次品之類的？
    if (is_fighting()) {
      tell_room(environment(), name()+"強撐著硬吞下一粒" + HIR + "生生造化丹" + HIC + "(粗糙)" + NOR + ",只覺得全身活力不斷湧現。\n");}
    else {
      tell_room(environment(), name()+"細心的把" + HIW + "銀針門" + HIY + "特製金創藥" + NOR + "敷在自己的身上。\n");}
//補血不能有小數 所以用(int)與非小數的方式來取整數 且括號後面的計算式以便debug
    me->receive_curing("kee",(int)(maxkee/100*4));
    me->receive_heal("kee",(int)(maxkee/100*8));
    me->receive_curing("sen",(int)(maxkee/100*3));
    me->receive_heal("sen",(int)(maxkee/100*4));
    me->receive_curing("gin",(int)(maxkee/100*3));
    me->receive_heal("gin",(int)(maxkee/100*4));
  }

  bout++; //為計算時間的變數累計+1
  me->set_temp("count_down",bout);

  if( !is_fighting() && query("kee") < query("eff_kee") && 40 < random(100) ) //加上機率 免得補太快
    command("3 exert recover");
  if( !is_fighting() && query("s_kee") < query("max_s_kee") && 10 < random(100) )
    command("10 exert reseckee");
  ::heart_beat(); //心跳函數的結尾
}

int heal_up()
{
  if (!is_fighting() && this_object()->query_temp("count_down") > 600)
  { //心跳一次 1:1.5(秒)==>1.5x40=1min, 15min=1.5x40x15=900 //縮短為10分 因為在沒有玩家經過或者存在時 心跳功能會停止
    message_vision (HIY + "$N見到小兵送來上級的手令，於是轉身飛奔離去，消失在你的眼前。\n" + NOR, this_object());
    destruct(this_object());
    return 1;
  } //此括號仍為判斷是否在戰鬥中的if下引號
  return ::heal_up();
}
