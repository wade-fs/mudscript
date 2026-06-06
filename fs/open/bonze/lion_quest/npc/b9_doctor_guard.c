#include <ansi.h>
#include "/open/open.h"
inherit NPC;

int bout=0; //給予本npc停留在該房間時間設定的變數

void create()
{
  set_name("銀針侍衛",({"doctor guard","guard","doctor","g"}));
  set("long","他是守護銀針門的侍衛，從眼睛散發出一股不容侵犯的威嚴，為了華神醫的大業，他不惜與任何人為敵。\n");
  set("nickname",HIC + "滅" + HIY + "獅" + NOR + "聯盟");
  set("gender","男性");
  set("class","doctor");
  set("combat_exp",7270000);
  set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","aggressive"); //主動攻擊玩家
  set("age",36);
//  set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
  set("doctor/vet",1); //具有看診師的資格，可以替人看診(vet)了！屬於非戰鬥時的攻擊技能
  set("doctor/sosman",1); //後三式 並 set("title",HBBLU+HIW + "ψ" + HIY + "七奇" + HIR + "秘針" + HIW + "ψ" + HIG + "傳人" + NOR);的mark 
  set("env/六絕針","YES"); //使用HIW"◎ " + HIY + "赤 炎 六 絕 針 " + HIW + "◎ 需求等級lv100??
//  set("doctor/save_die", 1); //『聖手回春術』並非戰鬥技能 關閉
  set("str",17);
  set("cps",25);
  set("per",15);
  set("int",30);
  set("kar", random(7)+15);
  set("force",12900);
  set("max_force",12900);
//  set("kee",39300); //不另設置 kee是因為 exp+force 似乎有加成超過max_kee
  set("max_kee",39300);
  set_skill("yu-needle",100);
  set_skill("stabber",30);
  map_skill("stabber","yu-needle");
  set_skill("parry",80);
  map_skill("parry","yu-needle");
  set_skill("force",95);
  set_skill("shinnoforce",100);
  map_skill("force","shinnoforce");
  set_skill("seven-steps",80);
  set_skill("move",70);
  map_skill("move","seven-steps");
  set_skill("dodge",90);
  map_skill("dodge","seven-steps");
//  set_skill("cure",70);
//  set_skill("godcure",60);
//  map_skill("cure","godcure");
//  set_skill("literate",60);
//  set_skill("unarmed",20);
  set("functions/gold-needle/level",50); //影響七奇針訣的 message_vision(HIY + "$N運起破穴指頂級技巧打散$n體內的內勁!!
  set("functions/break-kee/level",50); //影響七奇針訣的 message_vision(HIC + "$N運起金針封穴頂級技巧封阻$n的行動!!
  set("functions/heal/level",1); //神農治癒術
//  set("functions/acus/level",100); //似乎npc不能使用?heal
  set_temp("apply/armor",80); //+防的指令之一
  set_temp("apply/defense",10); //+防的指令之一
  set("force_factor",23);
  set("chat_chance_combat",30);
  set("chat_msg_combat",({
    (: perform_action("yu-needle.gold-needle") :),
    (: perform_action("yu-needle.break-kee") :),
//    (: perform_action("stabber.break-kee") :),
    }));
  set("chat_chance",random(30)+15);
  set("chat_msg",({
    (: random_move :), //單純隨機移動
  }));
  create_family("銀針門", 5, "內門弟子");
  set("family/family_name","銀針門");
  set("no_learn",1); //避免意外 所以設有禁止玩家學習技能
  delete("family/privs"); //刪除rb 5min保護 因create_family() 會自動產生 ("family/privs") 這是給門派首領使用的新手保護設定
  set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                    //為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域
  setup();
  carry_object("/open/doctor/obj/needle7.c")->wield();
  carry_object("/open/doctor/obj/cloth2.c")->wear();
  carry_object("/open/doctor/pill/human_pill.c")->set_amount(3);
  carry_object("/open/ping/obj/ring-2");
  add_money("gold",random(6));
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
  if( ob->query("class") == "poisoner" )
  {
    command("say 門主生平最恨毒害蒼生之人,今日我便為師除害,納命吧！");
    kill_ob(ob);
  }
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

int accept_kill(object who) 
{
//應該不論kill or fight 只要設定成一個 其他圍攻的npc 統統下fight好了 這樣比較容易
  who->set_temp("quests/bonze/fight", 1 ); //在玩家身上紀錄
  return 1;
}

int accept_fight(object who)
{
  who->set_temp("quests/bonze/fight", 1 );
  return 1;
}

void heart_beat()
{
  object me=this_object(),env;
  mapping exit;
  string *exit_name;
  int i,maxkee; //i為房間出口變數的存量 maxkee為紀錄玩家max_kee的存量
  env = environment(me);
  if(!me || !env) return;
  maxkee=me->query("max_kee",1);
  bout++; //為計算時間的變數累計+1 //設定在if 之前 避免被影響
  me->set_temp("count_down",bout);

//參考郭襄與趙高的逃跑模式 //以下得在使用前先定義
//  object me=this_object(),env;
//  mapping exit; 
//  string *exit_name;
//  int i;
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
//取消非戰鬥中補血 以增加與其他npc相異的情形 by blazakira
  if (is_fighting() && me->query("kee") < query("eff_kee")*0.7 && me->query_temp("unconcious") != 1 && (random(100) < 40))
  {
    tell_room(environment(), name()+"見情勢不妙，趕緊服下人靈丹，臉色頓時好多了。\n");
//補血不能有小數 所以用(int)與非小數的方式來取整數 且括號後面的計算式以便debug
    me->receive_curing("kee",(int)(maxkee/100*2));
    me->receive_heal("kee",(int)(maxkee/100*4));
    me->receive_curing("sen",(int)(maxkee/100*1));
    me->receive_heal("sen",(int)(maxkee/100*2));
    me->receive_curing("gin",(int)(maxkee/100*1));
    me->receive_heal("gin",(int)(maxkee/100*2));
    me->delete_busy();
    me->clear_condition();
    me->do_command("perform stabber.gold-needle");
  } else if ( is_fighting() && random(100) < 30 ) {
    command("perform yu-needle.gold-needle");
  } else if ( is_fighting() && random(100) < 10 ) {
    command("perform yu-needle.break-kee"); }

  if (is_fighting() && present("ice_ring",me)->query("equipped")== 0 ) //如果在戰鬥中 且沒穿ice_ring 那就穿上它吧
  {
    command("wear ice_ring");
  }

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
