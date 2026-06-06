#include <ansi.h>
#include "/open/open.h"
string magic();
inherit NPC;

int bout=0; //給予本npc停留在該房間時間設定的變數

void create()
{
  set_name("紫舞者",({"violet dancer","violet","dancer","d"}));
  set("long","為夜夢小築一派裡夜夢殿堂內堂初階弟子，今奉前代宮主之令前來支援。\n");
  set("nickname",HIC + "滅" + HIY + "獅" + NOR + "聯盟");
  set("gender","女性");
  set("class","dancer");
  set("combat_exp",8920000);
//  set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
  set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","aggressive"); //主動攻擊玩家
  set("age",18);
//  set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
 //練功型的mob 暫時不考慮太多的特攻
//  set("get_dan_sp",1); //後三式 exp >500000
  set("allow_meteor",1); //打倒水靈兒便可取得mark
  set("adv_dancer",1); //古舞者傳人 可使用fireball最高奧義 怒火燒盡九重天
//  set("allow_hellfire",1); //古舞者傳人 可使用地獄雷火術
//  set("allow_fdragon",1); //解謎並打倒月半彎可取得 set("title",HIW + "【" + HIR + "炎ソ舞者" + HIW + "】" + NOR);
  set("str", 30);
  set("cor", 27);
  set("cps", 45);
  set("per", 32);
  set("int", 37);
  set("kar", random(7)+28);
  set("atman",27000); //舞者使用法術後 相當於第二條的血量 需斟酌
  set("max_atman",9000); //數字較小是降低第二次打的難度
  set("mana",5000);
  set("max_mana",5000);
  set("force",4000);
  set("max_force",4000);
//  set("kee",44800); //不另設置 kee是因為 exp+force 似乎有加成超過max_kee
  set("max_kee",44800);
//  set_skill("parry",40);
  set_skill("spells",10);
  set_skill("magic",60);
//  set_skill("cure",60);
  set_skill("force",50);
  set_skill("literate",30);
  set_skill("move",50);
  set_skill("dodge",60);
//  set_skill("sword",50);
  set_skill("unarmed",10);
  set_skill("paull-steps",70);
  set_skill("dremagic",40);
//  set_skill("order-bee",120);
  set_skill("dreamforce",60);
  set_skill("dreamdance",80);
  set_skill("parry",90);
  map_skill("magic","dremagic");
  map_skill("dodge","paull-steps");
  map_skill("force","dreamforce");
  map_skill("move","paull-steps");
  map_skill("parry","dreamdance");
  map_skill("unarmed","dreamdance");
  set("spells/reflection/level",2);
  set("spells/confuse/level",2);
  set("spells/fireball/level",2);
//  set("spells/hellfire/level",2);
  set("spells/thunder/level",2);
  set("spells/mirror/level",2);
  set("spells/firedance/level",12);
  set("spells/dreamwings/level",1);
  set("spells/dreamcure/level",200); //dreamcure & dremagic的level 影響本治療術(dreamcure)效果
  set_temp("apply/armor",80); //+防的指令之一
  set_temp("apply/defense",20); //+防的指令之一
  set("force_factor",13);
  set("chat_chance_combat",50);
  set("chat_msg_combat",({
    (: magic :),
  }));
  set("chat_chance",random(30)+15);
  set("chat_msg",({
    (: random_move :), //單純隨機移動
  }));
  set("no_learn",1); //避免意外 所以設有禁止玩家學習技能
  create_family("夜夢小築",6,"內堂弟子"); //虹舞者 可設定為 七色舞者的最終階 或是 七色舞技大成而獲得的至上舞者稱號
//  set("family/family_name","夜夢小築"); //劍舞者 構想為仙劍轉舞者的進階職業 參考 公孫大娘劍舞
  delete("family/privs"); //刪除rb 5min保護 因create_family() 會自動產生 ("family/privs") 這是給門派首領使用的新手保護設定
  set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                    //為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域
  setup();
  carry_object("/open/dancer/obj/yuaboots.c")->wear();
  carry_object("/open/dancer/obj/maple_ribbon.c")->wield();
  carry_object("/open/dancer/obj/yuawaist.c")->wear();
  carry_object("/open/scholar/obj/icefan");
  carry_object("/open/ping/obj/ring-2");
  add_money("gold",random(13));
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

  if( is_fighting() )
  {
//    if(query_temp("ref_shield")!=1)
//      command("conjure reflection");
    if(query_temp("mana_shield")!=1)
      command("conjure dreamwings"); //提高使用機率 因此放在心跳裡
    if(random(100)>80) { //if(random(100)>85) 改為20%
//      command("conjure hellfire");
      command("conjure firedance");
      command("conjure confuse"); //加在此處 以機率控制
    }
  }
  else { //非戰鬥時
    if( query("eff_kee") < query("max_kee") )
      command("conjure dreamcure");
    if (random(3)>1) //設定為66%的回復速度?
    {
      if (me->query("atman") < me->query("max_atman") ) {
        command("respirate 200");
//        command("exert regenerate");
//        message_vision( me->name()+"閉上眼睛開始打坐。\n" + NOR,me);
      }
      if (me->query("force") < me->query("max_force") ) {
        command("ex 30");
//        message_vision( me->name()+"坐下來運氣用功\﹐一股內息開始在體內流動。\n" + NOR,me);
      }
    }
  } //戰鬥與否到此判斷結束

//自己補血的設定
//將影響的機率分別計算 戰鬥中與 非戰鬥中 且不能暈倒 暈倒還自補 那就搞笑哩XD
  if (me->query("kee") < maxkee*0.6 && me->query_temp("unconcious") != 1 && (random(100) < 30))
  {
    message_vision(HIG + "$N使出了夢玄法鑑中的" + HIC + "治療術" + HIG + "﹐只見一陣神奇光芒籠照全身。\n" + NOR, me);
    me->delete_busy();
    me->clear_condition();
//補血不能有小數 所以用(int)與非小數的方式來取整數 且括號後面的計算式以便debug
    me->receive_curing("kee",(int)(maxkee/100*2));
    me->receive_heal("kee",(int)(maxkee/100*5));
    me->receive_curing("sen",(int)(maxkee/100*1));
    me->receive_heal("sen",(int)(maxkee/100*3));
    me->receive_curing("gin",(int)(maxkee/100*1));
    me->receive_heal("gin",(int)(maxkee/100*3));
  }

  bout++; //為計算時間的變數累計+1
  me->set_temp("count_down",bout);
  ::heart_beat(); //心跳函數的結尾
}

string magic()
{
//  command("conjure confuse"); //定人的機率相當高 所以 改在心跳裡面
  command("conjure fireball");
//  command("conjure reflection"); //取消 因為會反彈 並會與dreamwings 合併
//  command("conjure firedance"); //攻擊傷害強 可能是因為 mob經驗值高的關係?? 沒有檔案 無法判斷 因此改在心跳裡
  command("conjure thunder");
  command("conjure dreamwings");
  return "\n";
}
 
int accept_fight(object who)
{
  command("say 您忍心欺負小女子我嗎？\n");
//  command("conjure reflection");
  command("conjure dreamwings");
  command("conjure confuse");
  command("wield icefan");
  command("wear all");
  fight_ob(who);
  message_vision( this_object()->name()+"一付弱不禁風，看起來就要昏倒的模樣。\n",who);
//應該不論kill or fight 只要設定成一個 其他圍攻的npc 統統下fight好了 這樣比較容易
  who->set_temp("quests/bonze/fight", 1 ); //在玩家身上紀錄
  return 1;
}

int accept_kill(object who)
{
  command("say 小女子弱如雨中蘭，不堪大俠您的一擊 ，您真忍心呀！（淒涼\n");
//  command("conjure reflection");
  command("conjure confuse");
  command("wield icefan");
  command("wear all");
//  kill_ob(who);
  who->set_temp("quests/bonze/fight", 1 );
  return 1;
}
/*
void die() //死掉會脫衣服 然後再度穿衣...orz  怪異 所以 設本函數測試XD by blazakira
{
  object ob=this_object();
  present("boots",ob)->set("equipped",0); //需注意這類的函數需要用分號(；)作為函數結尾
  present("belt",ob)->set("equipped",0);
  ::die();
}
*/
int heal_up()
{ //此外可以利用重生(召喚)時 直接紀錄重生時間 藉由玩家經過直接來做比較是否該destruct 不過累積隻數也是相當不錯的風險 所以此判斷方式不變
  if (!is_fighting() && this_object()->query_temp("count_down") > 600)
  { //心跳一次 1:1.5(秒)==>1.5x40=1min, 15min=1.5x40x15=900 //縮短為10分 因為在沒有玩家經過或者存在時 心跳功能會停止
    message_vision (HIY + "$N見到小兵送來上級的手令，於是轉身飛奔離去，消失在你的眼前。\n" + NOR, this_object());
    destruct(this_object());
    return 1;
  } //此括號仍為判斷是否在戰鬥中的if下引號
  return ::heal_up();
}
