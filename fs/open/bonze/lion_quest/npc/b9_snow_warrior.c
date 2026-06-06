#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string icef();
int bout=0; //給予本npc停留在該房間時間設定的變數

void create()
{
  set_name("白銀鬥士",({"silver warrior","silver","warrior","w"}));
  set("long","她已經一腳踏進高階武者的境界，目前她正在尋求對手，為了觸及更高的武者境界。\n");
  set("nickname",HIC "滅"HIY"獅"NOR"聯盟");
  set("gender","女性");
  set("class","fighter");
  set("combat_exp",7510000);
  set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","aggressive"); //主動攻擊玩家
  set("age",27);
  set("quest/gold-fire",1); //極火功技能使用mark
  set("quest/new_gold_fire",1); //極火功技能使用mark
//  set("ask_super_fighter"); //為仙雲之氣的quest_mark之一
//  set("allow_study",1); //為學習絕招的允許mark 與特攻無關
//三擇一 if( me->query("quests/read_snow") >=1 ) ==>set("title","雪蒼絕學傳人");
//("quests/read_snow")==1) && skill >= 70 為雪蒼武學之絕招『 奪 命 三 掌 』
//("quests/read_snow")==2) && skill >= 70 為雪蒼武學之絕招『 狂 風 無 影 腳 』
//("quests/read_snow")==3) && skill >= 70 為雪蒼武學之絕招『 "HIY"枯\"HIB" 葉"HIM" 殘"HIG" 星"HIW" 掌 』
  set("quests/read_snow",3);
//  set("functions/final-unarmed/level",100); //終極拳勢 沒設定自己的招式所以取消使用
//武者解了話.會變成一代武尊....同時可以使用終極拳勢...................by chan
//  set("final/ko_king",1);
//  set("final/limit",4); //應為使用招式數量 最高為4
//  set("bounds", 40000);
//  set("get_sha_sp", 1);
//  set("clan_kill",1);
//  set("no_hole",1);
//  set("no_plan_follow",1);
//  set("no_mount",1);
  set_temp("armor_vs_force",300);
//  set_temp("no_die_soon",1);
//  set_temp("rob",1); 
//  set_temp("no-plan",1);
//  set_temp("mount",1);
//  set_temp("follow",1);
//  set_temp("speed",1);
//  set_temp("empty",1);
//  set_temp("false",1);
//  set_temp("lock-link",1);
  set_temp("roared",1); //雙重roar 判斷 以增加mob差異性
  set("env/真氣封穴","YES"); //class為fighter時 可使用的設定
  set("env/衝穴","YES"); //class為fighter時 可使用的設定
  set("str", 40);
  set("cor", 20);
  set("cps", 20);
  set("per", 29);
  set("int", 33);
  set("kar", random(7)+28);
  set("bellicosity",1010);
  set("force", 20000);
  set("max_force",13000);
  set("s_kee",1000);
  set("max_s_kee",1000);
  set("sec_kee","tiger");
//  set("kee",65100); //不另設置 kee是因為 exp+force 似乎有加成超過max_kee
  set("max_kee",65100); //不想加傷害力 就只好加血+20000 單純拖時間
  set_skill("force",180);
  set_skill("snowforce",160);
  map_skill("force","snowforce");
  set_skill("unarmed",80);
//if(me->query("family/family_name")=="雪蒼派" && weapon->query("id")=="figring")
//if((skill>90)&&(k>80)&&me->query_skill_mapped("force")=="snowforce" && victim)
//參上所述 skill lv 91以上 且 使用相對應的武器及心法 便可使用絕招 當 lv100尚可使用雪蒼武學之奧義『 絕 學 三 連 擊 』
  set_skill("snow-martial",50);
  map_skill("unarmed","snow-martial");
  set_skill("parry",60);
  set_skill("snow-kee",70);
  map_skill("parry","snow-kee");
  set_skill("black-steps",100);
  set_skill("move",190);
  map_skill("move","black-steps");
  set_skill("dodge",180);
  map_skill("dodge","black-steps");
  set("functions/snow-powerup/level",100);
  set("functions/ice-fingers/level",1);
  set("functions/extra-kee/level",1);
  set_temp("apply/armor",40);
  set_temp("apply/defense",10);
  set_temp("apply/attack",50);
  set_temp("apply/damage",50);
  set("force_factor", 40);
  set("chat_chance_combat",50);
  set("chat_msg_combat",({
    (: icef :),
  }));
  set("chat_chance",random(30)+15);
  set("chat_msg",({
    (: random_move :), //單純隨機移動
  }));
  create_family("雪蒼派",7,"弟子");
//  set("family/family_name","雪蒼派");
  set("no_learn",1); //避免意外 所以設有禁止玩家學習技能
  delete("family/privs"); //刪除rb 5min保護 因create_family() 會自動產生 ("family/privs") 這是給門派首領使用的新手保護設定
  set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                    //為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域
  setup();
  carry_object("/open/ping/obj/fan-1.c");
  carry_object("/open/snow/obj/ring.c")->wield();
  carry_object("/open/snow/obj/blue-cloth.c")->wear();
  carry_object("/open/common/obj/flame-cboots.c")->wear();
  carry_object("/open/doctor/pill/pill2.c")->set_amount(random(5));
  carry_object("/open/killer/obj/k_ring");
  add_money("gold",random(7));
}

void init()
{
  add_action( "do_exert", "exert" );
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
    message_vision (HIY"$N大喊：無事生非者，殺無赦！\n"NOR, ob);
    fight_ob(ppl);
    command("follow "+ppl->query("id")); //會追殺的門派
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
        message_vision (HIR"$n眼尖發現了$N拿出一罐秘藥並喝了下去。\n"NOR, ob, ppl);
      }
      message_vision (HIR"$n看出$N的身上散發著不斷高漲的殺氣。\n"NOR, ob, ppl);
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

//set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
//針對class同為武者 使玩家無法對之使用roar 
int do_exert( string str )
{
  object me;
  me = this_player();
  if(me->query("class")=="fighter") //如果判斷該玩家等於 ("class","fighter") 就不跳出來
    if( str=="roar" ) 
    {
      message_vision(HIC"\n$N發覺$N被人用氣機鎖住，使$N無法發出吼聲…\n"NOR, me);
      message_vision(HIC"白銀鬥士對$N搖搖手說：本是武者一脈，相煎何太急呢？\n"NOR, me);
      return 1; //return 0;會將保留原訊息再加上述訊息 而 return 1 則否，不保留原exert roar 訊息
                //放在if裡面並不會影響到指令如本次的exert +heal 之類的 放在if裡面根據條件只有roar
    }
  return 0; //作為本int結束
}

int accept_fight(object who)
{
  who=this_player();
  command("say 果然江山代有才人出，讓我來試試你的功\力吧。\n");
  command("follow "+who->query("id")); //會追殺的門派
  command("wear bell_ring");
  fight_ob(who);
  command("charge "+who->query("id"));
  command("perform snow-kee.snow-powerup");
  command("cmd usekee "+who->query("id"));
//應該不論kill or fight 只要設定成一個 其他圍攻的npc 統統下fight好了 這樣比較容易
  who->set_temp("quests/bonze/fight", 1 ); //在玩家身上紀錄
  return 1;
}

int accept_kill(object who)
{
  who=this_player();
  command("say 口亨！不自量力。\n");
  command("follow "+who->query("id"));
  command("wear bell_ring");
  kill_ob(who);
  command("charge "+who->query("id"));
  command("perform snow-kee.snow-powerup");
  command("cmd usekee "+who->query("id"));
  who->set_temp("quests/bonze/fight", 1 );
  return 1;
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
    tell_room(environment(), name()+"一邊看著你一邊咬牙切齒地吞下一粒大還丹。\n");
//補血不能有小數 所以用(int)與非小數的方式來取整數 且括號後面的計算式以便debug
    me->receive_curing("kee",(int)(maxkee/100*2));
    me->receive_heal("kee",(int)(maxkee/100*4));
    me->receive_curing("sen",(int)(maxkee/100*1));
    me->receive_heal("sen",(int)(maxkee/100*2));
    me->receive_curing("gin",(int)(maxkee/100*1));
    me->receive_heal("gin",(int)(maxkee/100*2));
  }

  if( me->query("force_factor") < 30 )
  {
    me->set("force_factor",30);
  }

  if( !me->is_fighting() && !me->query("powerup_flag") )
  {
    command("perform snow-kee.snow-powerup");
  }

  if (is_fighting() && present("evil_fan",me)->query("equipped")== 0 ) //如果在戰鬥中 且沒穿evil_fan 那就穿上它吧
  {
    command("wear evil_fan");
  }

//  if( !me->is_fighting() && !me->query_temp("keeup") )
//  {
//    command("perform snowforce.extra-kee");
//  }

  if( !is_fighting() ) {
    if( query("sen") < query("eff_sen") ) // 125
      command( "exert refresh" );
    if( query("force") < query("max_force") ) // 1 -> 5.035
      command( "ex 160" );
    if( query("eff_kee") < query("max_kee") ) // 35
      command( "10 exert heal" );
    if( query("gin") < query("eff_gin") ) // 125
      command( "exert regenerate" );
    if( query("kee") < query("eff_kee") ) // 125 -> 300
      command( "3 exert recover" );
  }
  if(is_busy() ) {
    if(30>random(100)) {
      message_vision(HIW"\n只見$N暴起所有"HIY"真氣內勁"HIW"，$N全身隴罩在一股"HIC"綻藍氣勁"HIW"中，赫然已解開身上被封的穴道。\n"NOR,this_object());
      delete_busy();
    }
  }

  bout++; //為計算時間的變數累計+1
  me->set_temp("count_down",bout);
  ::heart_beat(); //心跳函數的結尾
}

string icef()
{
  command("perform snow-martial.ice-fingers");
  return "\n";
}

int heal_up()
{
  if (!is_fighting() && this_object()->query_temp("count_down") > 600)
  { //心跳一次 1:1.5(秒)==>1.5x40=1min, 15min=1.5x40x15=900 //縮短為10分 因為在沒有玩家經過或者存在時 心跳功能會停止
    message_vision (HIY"$N見到小兵送來上級的手令，於是轉身飛奔離去，消失在你的眼前。\n"NOR, this_object());
    destruct(this_object());
    return 1;
  } //此括號仍為判斷是否在戰鬥中的if下引號
  return ::heal_up();
}
/*
void die() //死掉會脫衣服 然後再度穿衣...orz  怪異 所以 設本函數測試XD by blazakira
{
  object ob=this_object();
  present("bell_ring",ob)->set("equipped",0); //需注意這類的函數需要用分號(；)作為函數結尾
  ::die();
}
*/
