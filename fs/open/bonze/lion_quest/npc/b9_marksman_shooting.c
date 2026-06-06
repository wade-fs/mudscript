inherit NPC;
#include <ansi.h>

void do_busy(); //額外busy的函數
int bout=0; //給予本npc停留在該房間時間設定的變數

void create()
{
  set_name("流星射手", ({ "shooting marksman","marksman","shooting","m" }) );
  set("long", "為了追尋強者之道，身懷絕技的這一代弟子的她們離開將軍府歷練，
冀望剷除世間不平事，求取俠名以威射日派。\n");
  set("nickname",HIC + "滅" + HIY + "獅" + NOR + "聯盟");
  set("gender", "女性" );
  set("class","marksman");
  set("combat_exp",8800000);
  set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","aggressive"); //主動攻擊玩家
  set("age", 29);
//  set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
  set("quest/gold-fire", 1 ); //技能奧義新增 解過fire-king , exp 三百萬以上 
//  set("marksman/punch_rock",1); //為使用" + HIC + "虛空馭天箭" + HIM + "的mark 隔空傷害玩家 暫不開放 讓玩家有路可跑 因本mob exp<1000
//  set("break-sun",1); //可使用破日驚天絕技的mark之一 並取得  set("title","$HBBLU$$HIB$破$HIY$日$HIC$驚$BLK$天$HIW$傳人$NOR$");
//  set("env/arrow_element","gold"); //使用破日驚天的絕技需要設定元素箭 //help 破日驚天
  set("str", 28);
  set("cor", 25);
  set("cps", 30);
  set("per", 32);
  set("int", 31);
  set("kar", random(7)+20);
  set("bellicosity",2100); //殺氣的設定 影響"god-shooting"
  set("max_force",6000);
  set("force",9000);
//  set("kee",43100); //不另設置 kee是因為 exp+force 似乎有加成超過max_kee
  set("max_kee",43100);
  set_skill("archery",70); //使用破日驚天需要本技能lv130以上
//技能需求經驗的區間 0~50, 50~100, ??, 200~350, 350~500, 500~700, 700~1000, 1000~1500, 1500~2000, 2000up
//技能需求等級的區間 0~6, 7~13, 14~20, 21~27, 28~34, 35~41, 42~48, 49~55, 56~62, 63~69, 70~76, 77~83, 84~90, 91up
//殺氣多寡亦有影響     int bell = (int)me->query("bellicosity")/100; if(bell>40) bell=40;if( bell < 20 ) return ;
//且 尚有內力的影響 int skill = (int)me->query_skill("force")/10; 其中之一絕技影響為me->set("force_factor",bell+skill);
  set_skill("god-shooting",76);
  map_skill("archery","god-shooting");
  set_skill("force",55);
  set_skill("iceforce",55);
  map_skill("force","iceforce");
  set_skill("rain-steps",80);
  set_skill("dodge",85);
  map_skill("dodge","rain-steps");
  set_skill("parry",70);
  map_skill("parry","rain-steps");
  set("functions/make_arrow/level",50);
  set("functions/flyarrow/level",100);
  set("functions/ten_kee/level",100);
  set("functions/m-archery/level",1); //使用條件之一為前項初級技能滿級lv100
//  set("functions/break-sun/level",1); //使用條件之一為前項初級技能滿級lv100(?
  set_temp("apply/armor",80);
  set_temp("apply/defense",20);
  set_temp("apply/attack",20);
  set_temp("apply/dodge",15);
  set("force_factor",11);
  set("chat_chance_combat",30);
  set("chat_msg_combat", ({
    (: do_busy :),
    (: perform_action("archery.ten_kee") :),
    (: perform_action("archery.m-archery") :),
//    (: perform_action("god-shooting.break-sun") :), //對現階段exp的玩家來說太強 因此關閉
  }));
  set("chat_chance",random(30)+15);
  set("chat_msg",({
    (: random_move :), //單純隨機移動
  }));
  create_family("射日派",5,"射手");
//  set("family/family_name","射日派");
  set("no_learn",1); //避免意外 所以設有禁止玩家學習技能
  delete("family/privs"); //刪除rb 5min保護 因create_family() 會自動產生 ("family/privs") 這是給門派首領使用的新手保護設定
  set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                    //為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域
  setup();
  carry_object("/open/doctor/pill/ff_pill.c")->set_amount(20);
/*  carry_object("/open/marksman/break-sun/obj/gold-arrow.c");
  carry_object("/open/marksman/break-sun/obj/gold-arrow.c");
  carry_object("/open/marksman/break-sun/obj/gold-arrow.c");
  carry_object("/open/marksman/break-sun/obj/gold-arrow.c");
  carry_object("/open/marksman/break-sun/obj/gold-arrow.c"); */
  carry_object("/open/marksman/obj/arrow-7");
  carry_object("/open/marksman/obj/arrow-7");
  carry_object("/open/marksman/obj/arrow-7");
  carry_object("/open/marksman/obj/arrow-7");
  carry_object("/open/marksman/obj/arrow-7");
  carry_object("/open/marksman/obj/arrow-8");
  carry_object("/open/marksman/obj/arrow-8");
  carry_object("/open/marksman/obj/arrow-8");
  carry_object("/open/marksman/obj/arrow-8");
  carry_object("/open/marksman/obj/arrow-8");
  carry_object("/open/marksman/obj/bow-7")->wield();
  carry_object("/open/gsword/obj/ring-1");
  add_money("gold",random(10));
}

int accept_kill(object who)
{
 command("say 呔，不知死活的傢伙，看姑奶奶我的厲害！");
 command("say 死吧！");
 command("cmd holdup arrow with bow");
 command("wear all");
//  command("kill "+who->query("id"));
//  command("perform god-shooting.break-sun"); //上列沒開本特攻 所以讓玩家先出手
//應該不論kill or fight 只要設定成一個 其他圍攻的npc 統統下fight好了 這樣比較容易
  who->set_temp("quests/bonze/fight", 1 ); //在玩家身上紀錄
  return 1;
}

int accept_fight(object who)
{
  command("say 嘿，就玩幾招當練手吧。");
  command("cmd holdup arrow with bow");
  command("wear all");
//  command("fight "+who->query("id"));
  fight_ob(who);
//  command("perform archery.ten_kee"); //讓玩家先出手 所以關閉 總不能fight 比kill 還狠XD
  who->set_temp("quests/bonze/fight", 1 );
  return 1;
}

void do_busy()
{
  object ob;
  if( random(7)>4 )
    command("exert flyarrow");
  message_vision(HIC + "流星射手強大的氣機鎖住你，令你無法行動！\n" + NOR,this_object());
  ob=this_object()->query("last_damage_from");
  if(ob)
    ob->start_busy(1);
  command("perform make_arrow");
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
  object me=this_object(),env;
  object wpn = me->query_temp("weapon");
  int i,j,p,k,maxkee; //k為房間出口變數的存量 maxkee為紀錄玩家max_kee的存量
//參考郭襄與趙高的逃跑模式 //以下得在使用前先定義
//  object me=this_object(),env;
  mapping exit; 
  string *exit_name;
//  int i; //改為k
  env = environment(me);
  if(!me || !env) return;
  maxkee=me->query("max_kee",1);
  if( (me->query("kee") < me->query("max_kee")*0.3) && (random(100) < 30) )
  {
    exit = env->query("exits");
    exit_name = keys(exit);
    k = random(sizeof(exit_name));
    command(exit_name[k]);
    k = random(sizeof(exit_name));
    command(exit_name[k]);
  }

//自己補血的設定
//將影響的機率分別計算 戰鬥中與 非戰鬥中 且不能暈倒 暈倒還自補 那就搞笑哩XD
  if (is_fighting() && me->query("kee") < maxkee*0.30 && me->query_temp("unconcious") != 1 && (random(100) < 40))
  {
    tell_room(environment(), name()+"強行運轉家傳秘技" + HIR + "鳳凰訣" + NOR + "，頓時全身活力不斷湧現。\n");
//補血不能有小數 所以用(int)與非小數的方式來取整數 且括號後面的計算式以便debug
    me->receive_curing("kee",(int)(maxkee/100*2));
    me->receive_heal("kee",(int)(maxkee/100*7));
    me->receive_curing("sen",(int)(maxkee/100*2));
    me->receive_heal("sen",(int)(maxkee/100*3));
    me->receive_curing("gin",(int)(maxkee/100*2));
    me->receive_heal("gin",(int)(maxkee/100*3));
  }

  p=random(10);
  i=wpn->query("arrow/amount");
  bout++; //為計算時間的變數累計+1
  me->set_temp("count_down",bout);

//技能裡面的判定  wpn->set("arrow/id","none");
  if (me->query("force") < me->query("max_force") && p < 4 )
  {
    command("eat pill");
  }

  if (is_fighting() && wpn->query("arrow/id","none") && present("arrow",me)){//在戰鬥中 且 沒箭 且 身上有箭 那就裝箭吧XD
    command("cmd holdup arrow with bow");
  }

  if (is_fighting()) //如果在戰鬥中 那就放技能吧
    if(p>4) {
      command("cmd holdup arrow with bow");
      command("perform archery.ten_kee");
      command("supershoot");
    }/* else if ( p=3 || p=4) //開到本特攻 對於此階段的玩家來說 相當強 因此關閉
    {
      command("cmd holdup arrow with bow");
      command("perform god-shooting.break-sun");
      command("supershoot");
    }*/
    else //if (p<3)
    {
      command("cmd holdup arrow with bow");
      command("perform archery.m-archery");
      command("supershoot");
    }

  ::heart_beat(); //心跳函數的結尾
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
