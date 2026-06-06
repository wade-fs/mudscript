#include <ansi.h>
inherit NPC;

string magic1();
string magic2();
string magic3();
string magic4();
int bout=0; //給予本npc停留在該房間時間設定的變數

void create()
{
  set_name("世外修士",({"xanadu monk","xanadu","monk","m"}));
  set("long", "炯炯有神的雙眼，斑白的雙鬢，他捋了捋自己下巴的白鬍鬚，微笑看著你。
風趣的談吐讓人對他產生好感，他專精於星象卜卦一類，是天道紫玄觀掌門陸
清風師兄門下最出色的弟子之一。\n");
  set("nickname",HIC + "滅" + HIY + "獅" + NOR + "聯盟");
  set("gender","男性");
  set("class","taoist");
  set("combat_exp",7630000);
//  set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
  set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","aggressive"); //主動攻擊玩家
  set("age",77);
//  set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
//  set("quest/ask_tendo_hawk1",1); //詢問陸清風"崑崙仙境"後接著詢問天道派宿世"使命"所取得的mark
//  set("quest/have_hawk",1); //交給陸清風"焚天魔王的人頭"後 祭拜陸皓雲後所取得的mark 可在戰鬥中使用【召喚靈鷹】
  set("marks/god-kee",1); //尋獲天書的quest 影響 紫龍鞭法 及 天罡戰氣 主要是看spells 與 necromancy 合起來的en為傷害力
//  set("adv_taoist",1); //強化紫幽及蒼冥之箭 並 set("title",三道魂˙（冥月、焰日、銀星）道使) ; //隨機三選一
//  set("get_icestorm",1); //需解謎後讀書學得奧義秘招【冰雪風暴】的mark 為下一段解謎條件之一 並非可用
//  set("allow_icestorm",1); //解完謎後便可使用【冰雪風暴】//此階段的exp<1000 所以不開放
  set("str",18);
  set("cps",23);
  set("cor",19);
  set("per",20);
  set("int",26);
  set("con",21);
  set("spi",21);
  set("kar", random(7)+30);
  set("s_kee",80);
  set("max_s_kee",80);
  set("sec_kee","tiger");
//  set("kee",45000); //不另設置 kee是因為 exp+force 似乎有加成超過max_kee
  set("max_kee",45000); //不開絕招就弱了很多 所以加血XD
  set("force",5000);
  set("max_force",5000);
  set("atman",5800);
  set("max_atman",5800);
  set("mana",8000); //天道法術所消耗的數值 影響mob放法術所造成的強度
  set("max_mana",8000);
  set("mana_factor",20);
  set_skill("literate",40);
  set_skill("cure",40);
  set_skill("taoism",40);
  map_skill("cure","taoism");
  set_skill("force",50);
  set_skill("gforce",50);
  map_skill("force","gforce");
  set_skill("g-steps",100);
  set_skill("dodge",140);
  map_skill("dodge","g-steps");
  set_skill("move",165);
  map_skill("move","g-steps");
  set_skill("magic",50);
  set_skill("gmagic", 55);
  map_skill("magic", "gmagic");
  set_skill("gwhip",85);
  set_skill("whip",75);
  map_skill("whip","gwhip");  
  set_skill("parry",80);
  map_skill("parry","gwhip");
  set_skill("spells",25);
  set_skill("necromancy",35);
  map_skill("spells","necromancy");
  set("spells/feeblebolt/level",80);
  set("spells/missible/level",85);
  set("spells/hardshell/level",55);
  set("spells/invocation/level",95);
  set("spells/godfight/level",80);
  set("spells/stopmove/level",1);
  set("spells/lightfire/level",1);
  set("spells/flee/level",10);
  set("spells/manabody/level",1);
  set_temp("apply/armor",60);
  set_temp("apply/defense",20);
  set("force_factor",10);
  set("chat_chance_combat",90);  //即85%的機率會使用下列任一函數 因為法術已有設定機率所以在此提高些
  set("chat_msg_combat",({
    (: magic1 :),
    (: magic2 :),
    (: magic3 :),
    (: magic4 :),
  }));
  set("chat_chance",random(30)+15);
  set("chat_msg",({
    (: random_move :), //單純隨機移動
  }));
  create_family("天道派",4,"修士");
//  set("family/family_name","天道派");
  set("no_learn",1); //避免意外 所以設有禁止玩家學習技能
  delete("family/privs"); //刪除rb 5min保護 因create_family() 會自動產生 ("family/privs") 這是給門派首領使用的新手保護設定
  set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                    //為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域
  setup();
  carry_object("/open/tendo/obj/goldwhisk.c")->wield();
  carry_object("/open/tendo/obj/hat1.c")->wear();
  carry_object("/open/tendo/obj/luboot")->wear();
  carry_object("/open/tendo/obj/robe1.c")->wear();
  carry_object("/open/tendo/obj/manapill.c")->set_amount(random(20));
  carry_object("/open/gsword/obj/ring-1");
  add_money("gold",random(8));
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

int accept_fight (object who)
{
  command("say 施主是否也有身不由己的時候？請手下留情吧。");
  command("conj hardshell");
  command("wear all");
  fight_ob(who);
  who->set_temp("quests/bonze/fight", 1 );
  return 1;
}

int accept_kill(object who)
{
  command("say 施主呀，何苦來哉呢～");
  command("conj hardshell");
  command("wear all");
//  kill_ob(who);
  who->set_temp("quests/bonze/fight", 1 );
  return 1;
}

string magic1()
{
  if(this_object()->query("mana")<=1000)
  {
    command("eat pill"); //此為恢復法力的丹藥 最高補mana 300
    command("cast king invocation");
  }  
  return "\n";
}

string magic2()
{
  if(random(2)<=1) 
    command("cast missible");
  else command("cast feeblebolt");
  return "\n";
}

string magic3()
{
  if(random(4)<=2)
    command("cast stopmove");
  return "\n";
}

string magic4()
{
  command("cast godfight");
  return "\n";
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
  if (is_fighting() && me->query("kee") < maxkee*0.3 && me->query_temp("unconcious") != 1 && (random(100) < 30))
  {
    tell_room(environment(), name()+"見情勢不妙，趕緊服下大還丹，臉色頓時好多了。\n");
//補血不能有小數 所以用(int)與非小數的方式來取整數 且括號後面的計算式以便debug
    me->receive_curing("kee",(int)(maxkee/100*2));
    me->receive_heal("kee",(int)(maxkee/100*4));
    me->receive_curing("sen",(int)(maxkee/100*1));
    me->receive_heal("sen",(int)(maxkee/100*2));
    me->receive_curing("gin",(int)(maxkee/100*1));
    me->receive_heal("gin",(int)(maxkee/100*2));
  }

  bout++; //為計算時間的變數累計+1
  me->set_temp("count_down",bout);
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
