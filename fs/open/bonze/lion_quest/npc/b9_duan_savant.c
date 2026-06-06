#include <ansi.h>
inherit NPC;

int exert_sunforce();
int bout=0; //給予本npc停留在該房間時間設定的變數

void create()
{
  set_name("內閣大學士",({"temple savant","temple","savant","s"}));
  set("long","大學士一職乃唐中宗時首創，原職為協助皇帝批閱\奏章，起草詔書等。
現由段家招攬，為了段家的百年大計奔波著。\n");
  set("nickname",HIC + "滅" + HIY + "獅" + NOR + "聯盟");
  set("gender","女性");
  set("class","scholar");
  set("combat_exp",8000002); //使出六脈神劍連續技的判斷條件之一 3. 2000000..5000000 2. 5000001..8000000 1. 8000001..32000000
  set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","aggressive"); //主動攻擊玩家
  set("age",50);
//  set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
 //練功型的mob 暫時不考慮太多的特攻
//  if(be>3000 || user->query("six_spsp")) limit=4;
//  if(user->query("six_spsp") && user->query("env/quick_fan")) limit=2;
//  if(wizardp(user) && user->query("env/quick_fan")) limit=2;
//  set("six_spsp",1); //使用武器飄雲扇的特攻時 可以減少等待時間
//  set("env/quick_fan","YES"); //使用武器飄雲扇的特攻時 可以減少等待時間
//使用本mark的判斷條件為六脈神劍技能裡 int level=(int)(me->query_skill("six-fingers",1));
//if ( level >= 100 && me->query("marks/six_sp")==3 && me->query("family/family_name") == "段家")
  set("marks/six_sp",3); //skills lv 100 & 此mark 即可發出後三式
  set("marks/sun-finger",1); //使用一陽指氣的mark
// lyssa.c 狂犬病 by babe
// mob  set( "no_lyssa", 1 ); 此 mob 免疫
// room set( "no_lyssa", 1 ); 此 room 為免疫區
//  set("no_lyssa",1);
//  set("env/超級連擊",1); //wiz 才有用的六脈神劍技能減緩延遲功能
  set("env/六絕劍","YES"); //開啟六脈神劍連擊功能
//飄陽指勁有專用武器......傷害最高700 fun=me->query("functions/fan-finger/level"); damage=fun*(random(7)+1); if(damage > 700) damage=700;
//當飄陽指勁的等級到達90以上時可以set fan_auto_shoot，會自動射出指勁
//  set("env/fan_auto_shoot","YES"); //本mob沒使用該武器 所以關閉
//  set("env/飄陽扇連擊","YES"); //本mob沒使用該武器 所以關閉
//  set("functions/fan-finger/level",120); //飄陽指勁
  set("str", 15);
  set("cor", 22);
  set("cps", 10);
  set("per", 31);
  set("int", 40);
  set("kar", random(7)+26);
//  set("kee",42000); //不另設置 kee是因為 exp+force 似乎有加成超過max_kee
  set("max_kee",42000); //弱了些所以加血XD
  set("force",9000);
  set("max_force",9000);
  set_skill("unarmed",30);
  set_skill("force",180);
  set_skill("move", 80);
  set_skill("dodge", 80);
  set_skill("parry", 70);
  set_skill("stabber",90);
  set_skill("literate",70);
  set_skill("sunforce",120);
  set_skill("linpo-steps",80);
  set_skill("six-fingers",100);
  map_skill("force","sunforce");
  map_skill("dodge","linpo-steps");
  map_skill("move","linpo-steps");
  map_skill("parry","six-fingers");
  map_skill("stabber","six-fingers");
  map_skill("unarmed","six-fingers");
  set("functions/handwriting/level",1);
  set_temp("apply/armor",60); //+防的指令之一
  set_temp("apply/defense",10); //+防的指令之一
  set("force_factor", 30);
  set("chat_chance_combat", 40);
  set("chat_msg_combat", ({
    (: perform_action("stabber.handwriting") :),
  }));
  set("chat_chance",random(30)+15);
  set("chat_msg",({
    (: random_move :), //單純隨機移動
  }));
  create_family("段家",10,"大學士"); //設定為 與master_duan段雲 同一代的人物 因為職稱的關係
                                     //第9代以上為長老級別(暫定)
//  set("family/family_name","段家");
  set("no_learn",1); //避免意外 所以設有禁止玩家學習技能
  delete("family/privs"); //刪除rb 5min保護 因create_family() 會自動產生 ("family/privs") 這是給門派首領使用的新手保護設定
  set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                    //為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域
  setup();
  carry_object("/open/ping/obj/robe-1.c")->wear();
  carry_object("/open/ping/obj/wrists-1.c")->wear();
  carry_object("/open/ping/obj/gloves1.c")->wear();
  carry_object("/open/ping/obj/fan1.c")->wield();
  carry_object("/open/ping/obj/ring-2");
  carry_object("/open/ping/obj/poison_pill.c")->set_amount(5);
  add_money("gold",random(16));
}

void init()
{
  set_heart_beat(1); //設定為一次的心跳
  ::init(); //只設定本行時與雪蒼liu 相同 會執行 非戰鬥時 回靈力的判斷 不如說 非戰鬥時 一樣會執行指令:p
  call_out("greeting", 1, this_player());
}

void greeting()
{
  object ppl=this_player(),ob=this_object();
  if(!userp(ppl)) return; //直接對於非玩家的角色忽略 應可避免殺手呼叫影武者 天道的招喚術這類的情況？
  if (!ob->is_fighting() && ppl->query_temp("quests/bonze/fight") == 1
      && ppl->is_fighting() && (ob->query("kee") > ob->query("max_kee")*0.3))
  {
    message_vision (HIY + "$N大喊：無事生非者，殺無赦！\n" + NOR, ob);
    fight_ob(ppl);
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
      tell_room(environment(), name()+"吃下一粒百花清心露" + HIC + "(強效)。\n" + NOR);}
    else { //非戰鬥時
      if( query("kee") < query("eff_kee") && (random(100) < 40) ) {
        command("exert recover"); }
      if( query("eff_kee") < query("max_kee") && (random(100) < 50) ) {
        command("exert heal"); }
      if( query("eff_kee") < query("max_kee") && (random(100) < 10) ) {
        command("eat flower pill"); } //解毒 解狀態
    }
  }

  bout++; //為計算時間的變數累計+1
  me->set_temp("count_down",bout);
  ::heart_beat(); //心跳函數的結尾
}

int exert_sunforce()
{
  object ob=this_object();
  if( !present("sunforce finger",ob) )
  {
    command("say 嘖，小子看招！");
    command("exert sun-finger");
    command("wield finger");
  }
  return 1;
}

int accept_kill(object who)
{
  who=this_player();
  command("unwield all");
  command("wield fan");
//  command("kill "+who->query("id"));
  command("exert sun-finger");
  command("perform unarmed.handwriting");
  command("wield finger"); 
  command("wear all");
//應該不論kill or fight 只要設定成一個 其他圍攻的npc 統統下fight好了 這樣比較容易
  who->set_temp("quests/bonze/fight", 1 ); //在玩家身上紀錄
  return 1;
}

int accept_fight(object who)
{
  who=this_player();
  command("unwield all");
  command("wield fan");
  command("exert sun-finger");
  fight_ob(who);
  command("perform unarmed.handwriting");
  command("wield finger"); 
  command("wear all");
  who->set_temp("quests/bonze/fight", 1 );
  return 1;
}

int heal_up()
{
  if (!is_fighting() && this_object()->query_temp("count_down") > 600)
  {//心跳一次 1:1.5(秒)==>1.5x40=1min, 15min=1.5x40x15=900 //縮短為10分 因為在沒有玩家經過或者存在時 心跳功能會停止
    message_vision (HIY + "$N見到小兵送來上級的手令，於是轉身飛奔離去，消失在你的眼前。\n" + NOR, this_object());
    destruct(this_object());
    return 1;
  } //此括號仍為判斷是否在戰鬥中的if下引號
  return ::heal_up();
}
