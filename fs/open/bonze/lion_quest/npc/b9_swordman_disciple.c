#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void do_busy(); //額外busy的函數
string do_special_fight(); //參考金刀門的替換技能函數
object ob;
int bout=0; //給予本npc停留在該房間時間設定的變數

void create()
{
  set_name("冰山劍俠", ({ "swordman disciple", "swordman", "disciple", "d" }) );
  set("long","師承流星三劍客中劍法最精的女俠寒紫冰，青出於藍更勝於藍的她奉師父之令下山修行。\n");
  set("nickname",HIC + "滅" + HIY + "獅" + NOR + "聯盟");
  set("gender", "女性" );
  set("class","swordsman");
  set("combat_exp",8010000);
  set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","aggressive"); //主動攻擊玩家
  set("age", 27);
//  set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
//  set("env/連擊","YES"); //仙劍兩招劍技似乎沒有連擊的set
  set("str", 19);
  set("cor", 28);
  set("cps", 33);
  set("per", 28);
  set("int", 37);
  set("kar", random(7)+30);
  set("bellicosity",1010); //殺氣的設定
  set("max_mana",1000);
  set("mana",1000);
  set("force",17000);
  set("max_force",12000);
//  set("kee",41800); //不另設置 kee是因為 exp+force 似乎有加成超過max_kee
  set("max_kee",41800);
  set_skill("force",130);
  set_skill("shaforce",110);
  map_skill("force","shaforce"); 
  set_skill("sha-steps",80);
  set_skill("dodge",85);
  map_skill("dodge","sha-steps");
  set_skill("move",70);
  map_skill("move","sha-steps");
  set_skill("sword",70);
  set_skill("shasword",94); //強力技能攻擊等級需求skill_level >= 95
  map_skill("sword","shasword");
  set_skill("parry",40);
  set_skill("sun_fire_sword",80);
  map_skill("parry","sun_fire_sword");
  set_skill("unarmed",40);
  set("functions/swordkee/level",100); //劍氣(swordkee)
  set("functions/sha_kee/level",100); //劍影連陽(sha_kee)
  set("functions/sunswordkee/level",1); //連陽七絕斬(sunswordkee)
  set_temp("apply/armor",80);
  set_temp("apply/defense",20);
  set("force_factor",25);
  set("chat_chance_combat",60); //即60%的機率會使用下列任一函數
  set("chat_msg_combat",({
    (: do_busy :),
    (: perform_action,"sword.swordkee" :),
    (: perform_action,"sword.sha_kee" :), //沒看到npc使用過 暫時關閉
    (: perform_action,"sun_fire_sword.sha_kee" :), //並非主要的map_skill 所以關閉
//    (: do_special_fight :), //太強 所以暫時關閉
  }));
  set("chat_chance",random(30)+15);
  set("chat_msg",({
    (: random_move :), //單純隨機移動
  }));
//以下八招 依序判斷 且只能存在一招 例如啟用第六式 則從set("dragon-sword",1) 到set("sha-stop-5",1) 都得by pass 
//因為不會去判斷第七式 所以也要by pass
//  set("dragon-sword",1); //仙劍劍法 (shasword)技能mark 劍影連陽 七陽連天 ("family/master_name")=="鄭士欣"
//  set("sha-stop-1",1); //仙劍劍法 (shasword)技能mark 仙劍禁斷之連陽七訣第一式『" + HIR + "烈陽" + HIW + "』("family/master_name")=="張乘風"
//  set("sha-stop-2",1); //仙劍劍法 (shasword)技能mark 仙劍禁斷之連陽七訣第二式" + HIW + "『" + HIR + "殘陽" + HIW + "』("family/master_name")=="張乘雲"
//  set("sha-stop-3",1); //仙劍劍法 (shasword)技能mark 仙劍禁斷之連陽七訣第三式" + HIW + "『" + HIY + "豔陽" + HIW + "』("family/master_name")=="唐鈺"
//  set("sha-stop-4",1); //仙劍劍法 (shasword)技能mark 仙劍禁斷之連陽七訣第四式" + HIW + "『" + HIY + "暖陽" + HIW + "』("family/master_name")=="趙鶴"
//  set("sha-stop-5",1); //仙劍劍法 (shasword)技能mark 仙劍禁斷之連陽七訣第五式" + HIW + "『" + HIC + "冬陽" + HIW + "』("family/master_name")=="梅影"
  set("sha-stop-6",1); //仙劍劍法 (shasword)技能mark 仙劍禁斷之連陽七訣第六式" + HIW + "『" + HIY + "朝陽" + HIW + "』("family/master_name")=="何雙雙"
//  set("sha-stop-7",1); //仙劍劍法 (shasword)技能mark 仙劍禁斷之連陽七訣第七式" + HIW + "『" + HIY + "夕陽" + HIW + "』 以上皆非 query_skill("shasword",1) >=60
  set("quest/sun_fire_sword",1); //修煉 連陽七訣劍法 (sun_fire_sword) 技能mark 可使用help sun_fire_sword 看技能說明
  set("get_sha_sp",1); //修煉 連陽七訣劍法 (sun_fire_sword) 技能mark
//  set("quests/sunfire",1); //為連陽七訣劍法特攻 需解謎 並打倒fire-king後 跟風青雲說話所取得 連陽七絕斬 的mark //太強 所以暫時關閉
// limit= skill_level; if(me->query("family/family_name")!="仙劍派"  || me->query("killyao")==1) return action[7];
//根據上一行 應該是無視技能等級 直接設定技能威力為最強?
//if(me->query("killyao")==1)  return notify_fail("你無法使用連陽劍\n"); //或者根據技能sha_kee所表示 為不能使用連陽劍?
//  set("killyao",1); //打倒仙劍quest mob 娃娃魚 所得到 連陽七訣劍法 (sun_fire_sword) 技能mark
  create_family("仙劍派",5,"劍俠");  //劍侍 侍女 ex:《長空劍神》《無雙劍神》的稱A
//  set("family/family_name","仙劍派"); //新手、劍侍、劍童、劍手、劍士、劍客、劍師、劍仙、劍神、劍聖（劍皇 劍尊 劍聖 劍神）
  set("no_learn",1); //避免意外 所以設有禁止玩家學習技能
  delete("family/privs"); //刪除rb 5min保護 因create_family() 會自動產生 ("family/privs") 這是給門派首領使用的新手保護設定
  set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                    //為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域
  setup();
  carry_object("/open/gsword/obj/spsword-2.c")->wield();
  carry_object("/open/gsword/obj/yu-armband.c")->wear();
  carry_object("/open/gsword/obj/yuboots.c")->wear();
  carry_object("/open/gsword/obj/yubracelet.c")->wear();
  carry_object("/open/gsword/obj/yuskirt.c")->wear();
  carry_object("/open/gsword/obj/robe.c")->wear();
// /open/fire-hole/obj/p-pill 毒龍精元 短時+magic spells en的效果 50 (eat pill)
// /open/mon/obj/thousand-nectar 千年花蜜 短時+force 20000 非maxforce (drink nectar)
// /open/clan/area/home/hae_bag 卍乾坤袋卍(Universal bag) 可以裝物品 且可以丟給他人的袋子 目前還沒想到可以裝什麼
//注意 不可使用丟袋子的功能 但是或許可以使用在quest上(大心)
  carry_object("/open/common/obj/pill2")->set_amount(random(5)); //回血+300
  carry_object("/open/common/obj/plaster2")->set_amount(random(5));
  carry_object("/open/gsword/obj/ring-1"); //似乎wear 看不到使用的訊息
  add_money("gold",random(12));
}

void init() //使用此函數 當遇上玩家時 可方便做出判斷
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
//參考郭襄與趙高的逃跑模式 //以下得在使用前先定義
  object me=this_object(),env;
  mapping exit; 
  string *exit_name;
  int i,maxkee; //i為房間出口變數的存量 //maxkee為紀錄玩家max_kee的存量
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
  if (me->query("kee") < maxkee*0.5 && me->query_temp("unconcious") != 1 && (random(100) < 20))
  {
    if (is_fighting()) {
      tell_room(environment(), name()+"見情勢不妙，趕緊服下大還丹，臉色頓時好多了。\n"); }
    else {
      tell_room(environment(), name()+"細心的把" + HIW + "銀針門" + HIY + "特製金創藥" + NOR + "敷在自己的身上。\n"); }
//補血不能有小數 所以用(int)與非小數的方式來取整數 且括號後面的計算式以便debug
    me->receive_curing("kee",(int)(maxkee/100*2));
    me->receive_heal("kee",(int)(maxkee/100*6));
    me->receive_curing("sen",(int)(maxkee/100*1));
    me->receive_heal("sen",(int)(maxkee/100*3));
    me->receive_curing("gin",(int)(maxkee/100*1));
    me->receive_heal("gin",(int)(maxkee/100*3));
  } else if ( is_fighting() && random(100) < 65 ) {
    command("perform sword.sha_kee");
  } else if ( is_fighting() && random(100) < 50 ) {
    command("perform sword.swordkee");
  }

  if (is_fighting() && present("ruby_ring",me)->query("equipped")== 0 ) //如果在戰鬥中 且沒穿ruby_ring 那就穿上它吧
  {
    command("wear ruby_ring");
  }

  bout++; //為計算時間的變數累計+1
  me->set_temp("count_down",bout);
  ::heart_beat(); //心跳函數的結尾
}

void do_busy()
{
  if( random(7)>4 )
    message_vision(HIC + "寒冰劍寒氣逼人 ,瞬間你被凍結了。\n" + NOR,this_object());
  ob=this_object()->query("last_damage_from");
  if(ob)
    ob->start_busy(1);
}

string do_special_fight()
{
  if( query_skill_mapped("sword") == "shasword" ) {
    command("perform sword.sha_kee");
    map_skill("sword", "sun_fire_sword");
  }
  else if( query_skill_mapped("sword") == "sun_fire_sword" ) { 
    command("perform sun_fire_sword.sunswordkee");
    map_skill("sword", "shasword");
  }
  command("perform sun_fire_sword.sunswordkee");
  return "";
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
