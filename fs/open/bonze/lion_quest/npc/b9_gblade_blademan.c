#include <ansi.h>
inherit NPC;

string do_special_fight();
int bout=0; //給予本npc停留在該房間時間設定的變數

void create()
{
  set_name("金甲刀客",({"golden blademan","golden","blademan","b"}));
  set("long","身穿一身黃金甲，手持一把柳月刀，不怒自威的國字臉，和強健無比的魁梧
身材他橫眉豎目地看著你，他很缺錢，所以血氣方剛的他巴不得你向他挑釁。\n");
  set("nickname",HIC + "滅" + HIY + "獅" + NOR + "聯盟");
  set("gender","男性");
  set("class","blademan");
  set("combat_exp",7030000);
  set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","aggressive"); //主動攻擊玩家
  set("age", 40);
  set("env/連擊","YES"); //開啟幔羅千葉刀法連擊 很強
//  set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
  set("str", 30);
  set("cor", 22);
  set("cps", 10);
  set("per", 15);
  set("int", 30);
  set("kar", random(7)+14);
  set("force",10000);
  set("max_force",10000);
//  set("kee",48500); //不另設置 kee是因為 exp+force 似乎有加成超過max_kee
  set("max_kee",48500);
  set_skill("dodge", 160);
  set_skill("move", 170);
  set_skill("blade",60);
  set_skill("fast-blade", 90);
  map_skill("blade","fast-blade");
  set_skill("parry",40);
  set_skill("gold-blade",60);
  map_skill("parry","gold-blade");
  set_skill("force",120);
  set_skill("sixforce",115);
  map_skill("force","sixforce");
  set("functions/gold-dest/level",25);
  set("functions/fast-dest/level",25);
//魔刀失傳之奧義『盧山不動一劍痕』只有 npc 和 swy 可用(確定
//  set("functions/power-dest/level",100); //perform dragon-blade.swy ?? 雖然只要是刀客就可以用 但是本mob還是不開放使用
  set_temp("apply/armor",60); //+防的指令之一
  set_temp("apply/defense",5); //+防的指令之一
  set("force_factor",25);
  set("chat_chance_combat",50); //有放特攻很強
  set("chat_msg_combat",({
    (: do_special_fight :),
  }));
  set("chat_chance",random(30)+15);
  set("chat_msg",({
    (: random_move :), //單純隨機移動
  }));
  create_family("金刀門",8,"弟子");
//  set("family/family_name","金刀門");
  set("no_learn",1); //避免意外 所以設有禁止玩家學習技能
  delete("family/privs"); //刪除rb 5min保護 因create_family() 會自動產生 ("family/privs") 這是給門派首領使用的新手保護設定
  set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                    //為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域
  setup();
  carry_object("/open/doctor/pill/pill2.c")->set_amount(random(5));
  carry_object("/open/gblade/obj/moon-blade.c")->wield();
  carry_object("/open/ping/obj/ring-2.c");
  carry_object("/autoload/ring")->wear();
  carry_object("/open/gblade/obj/gold-armor.c")->wear();
  carry_object("/open/gblade/obj/gold-boots.c")->wear();
  add_money("gold",random(1));
}

string do_special_fight()
{
  if( query_skill_mapped("blade") == "fast-blade" ) {
    command("perform blade.fast-dest");
    map_skill("blade", "gold-blade");
  }
  else if( query_skill_mapped("blade") == "gold-blade" ) {
    command("perform blade.gold-dest");
    map_skill("blade", "fast-blade");
  }
  command("perform blade.gold-dest");
  return "";
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
  int i,maxkee; //i為房間出口變數的存量 maxkee為紀錄玩家max_kee的存量
  env = environment(me);
  if(!me || !env) return;
  maxkee=me->query("max_kee",1);
  if( (me->query("kee") < me->query("max_kee")*0.3) && (random(100) < 30) )
  {
    exit = env->query("exits");
    exit_name = keys(exit);
    i = random(sizeof(exit_name));
    command(exit_name[i]);
    i = random(sizeof(exit_name));
    command(exit_name[i]);
  }

  bout++; //為計算時間的變數累計+1 //設定在if 之前 避免被影響
  me->set_temp("count_down",bout);

  if (is_fighting() && present("ice_ring",me)->query("equipped")== 0 ) //如果在戰鬥中 且沒穿ice_ring 那就穿上它吧
  {
    command("wear ice_ring");
  }

//自己補血的設定
//將影響的機率分別計算 戰鬥中與 非戰鬥中 且不能暈倒 暈倒還自補 那就搞笑哩XD
//取消非戰鬥中補血 以增加與其他npc相異的情形 by blazakira
  if (is_fighting() && me->query("kee") < query("eff_kee")*0.6 && me->query_temp("unconcious") != 1 && (random(100) < 30))
  {
    tell_room(environment(), name()+"見情勢不妙，趕緊服下大還丹，臉色頓時好多了。\n");
//補血不能有小數 所以用(int)與非小數的方式來取整數 且括號後面的計算式以便debug
    me->receive_curing("kee",(int)(maxkee/100*2));
    me->receive_heal("kee",(int)(maxkee/100*4));
    me->receive_curing("sen",(int)(maxkee/100*1));
    me->receive_heal("sen",(int)(maxkee/100*2));
    me->receive_curing("gin",(int)(maxkee/100*1));
    me->receive_heal("gin",(int)(maxkee/100*2));
    me->delete_busy();
//    me->clear_condition();
  } else if ( is_fighting() && random(100) < 30 ) {
    if( query_skill_mapped("blade") == "fast-blade" ) {
      command("perform blade.fast-dest");
      map_skill("blade", "gold-blade");
    }
    else if( query_skill_mapped("blade") == "gold-blade" ) { 
      command("perform blade.gold-dest");
      map_skill("blade", "fast-blade");
    }
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
