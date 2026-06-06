//作為守門的mob 無須太強 減少因mob死亡而失去quest的起點 by blazakira

#include <ansi.h> //代表顏色的函數
inherit NPC;

string do_help();
object ob=this_object();
string firef();
int bout=0; //給予本npc停留在該房間時間設定的變數

void create()
{
  set_name("瀧山護法",({"guard fighter","fighter","guard","f"}));
  set("long","瀧山派的第一線護派弟子，為十大門派聯盟的先鋒成員。\n");
  set("nickname",HIC "滅"HIY"獅"NOR"聯盟");
  set("gender","男性");
  set("class","fighter");
  set("combat_exp",5510000);
  set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//  set("attitude","aggressive"); //主動攻擊玩家
  set("age",41);
  set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
  set("quest/gold-fire",1); //極火功技能使用mark
  set("quest/new_gold_fire",1); //極火功技能使用mark
//  set("del_delay",1); // 取消自身 busy by swy 為瀧山拳法busy的判斷 現已取消
//  set("env/狂擊","YES"); //瀧山絕學 (lungshan) 沒有這設定 已改為下一行的set
  set("env/瀧山連擊","YES"); //連擊等級判斷為 sklv=(int)me->query_skill("lungshan",1)/10;
  set("super_fire",1); //瀧山拳禁斷技的奧密==>set("title","瀧山絕學傳人");
//  set("go_ya",1); //打倒惡獸--獨角虎的入門quest 的mark
//  set("quests/ya",1); //打敗『血魔』葉狂 並交回其腦袋 然後可以學瀧山的終極奧義『赤焰神掌』
//  set("fire_strike",1); //瀧山的終極奧義『赤焰神掌』==>set("title","瀧山奧義傳人"); 以內力為基準分3000up 2000up 1000up 三階段
//  set("get_force",1); //為其他門派打倒葉狂 第一次所得到的獎勵mark紀錄
  set("kang-power", 1 ); //補充lungshan可以解到kang-power...2002-12-25 --by kalin<<<打倒fire-king才有的mark
  set("env/衝穴","YES"); //class為fighter時 可使用的設定 // 武者自動衝封穴系統 by swy 請 wiz 別把條件說出去 thx
//  set("env/真氣封穴","YES"); //class為fighter時 可使用的設定 為聚靈山莊限定的set??
//  set("functions/final-unarmed/level",100); //終極拳勢 沒設定自己的招式所以取消使用
//武者解了話.會變成一代武尊....同時可以使用終極拳勢...................by chan
//  set("final/ko_king",1);
//  set("final/limit",4); //應為使用招式數量 最高為4
  set("force",15000);
  set("max_force",10000);
  set("str",25);
  set("kar", random(7)+23);
//  set("kee",46400); //不另設置 kee是因為 exp+force 似乎有加成超過max_kee
  set("max_kee",46400);
  set_skill("unarmed",85);
  set_skill("dodge",65);
  set_skill("parry",60);
  set_skill("force",160);
  set_skill("haoforce",160);
  set_skill("fire-kee",65);
//if(me->query("family/family_name")=="瀧山派"&&weapon->query("id")=="crazy dragon")
//if((k>85)&&(skill_level>90)&&(me->query_skill_mapped("force")=="haoforce"))
  set_skill("lungshan",85); //因此技能達85以上 並配合心法還有武器 即可觸發一招絕技
  set_skill("henma-steps",70);
  map_skill("dodge","henma-steps");
  map_skill("parry","fire-kee");
  map_skill("unarmed","lungshan");
  map_skill("force","haoforce");
  set("functions/kang_kee/level",1);
  set("functions/kang_power/level",1);
  set_temp("apply/armor",50); //+防的指令之一
  set_temp("apply/defense",5); //+防的指令之一
  set("force_factor",22);
  set("chat_chance_combat",20);
  set("chat_msg_combat",({
//    (: random_move :), //因為主要是顧門口 所以不移動
    (: firef :),
    (: do_help :),
  }));
  create_family("瀧山派", 9, "弟子");
//  set("family/family_name","瀧山派");
  set("no_learn",1); //避免意外 所以設有禁止玩家學習技能
  delete("family/privs"); //刪除rb 5min保護 因create_family() 會自動產生 ("family/privs") 這是給門派首領使用的新手保護設定
  set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                    //為巡邏npc的判斷 以避免觸發本區mob無意義的呼叫 且可避免本npc離開本區域
  setup();
  carry_object("/open/ping/obj/iceger.c")->wield(); //由spi int unarmed_lv 三個數值給予傷害的武器 目前暫定前二者為隨機 就看玩家運氣囉
  carry_object("/open/common/obj/soul-fan.c")->wield();
//  carry_object("/open/wu/obj/claw.c")->wield();
  carry_object("/open/wu/obj/fight_robe")->wear();
  carry_object("/open/doctor/pill/pill2.c")->set_amount(random(5));
  carry_object("/open/ping/obj/ring-2");
  add_money("gold",random(7));
}

void init()
{
  object who;
  :: init();
  add_action( "do_exert", "exert" );
  if(interactive(who =this_player()) && !is_fighting() )
    add_action("do_report","report");
  set_heart_beat(1); //啟動1個心跳函數
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
      message_vision(HIC"瀧山護法對$N搖搖手說：本是武者一脈，相煎何太急呢？\n"NOR, me);
      return 1; //return 0;會將保留原訊息再加上述訊息 而 return 1 則否，不保留原exert roar 訊息
                //放在if裡面並不會影響到指令如本次的exert +heal 之類的 放在if裡面根據條件只有roar
    }
  return 0; //作為本int結束
}

int do_report(string arg)
{
  object who=this_player();
  if( !arg || arg != getuid(who) ) //回報的id 不存在 or 回報的id !=玩家原id
    return notify_fail("瀧山護法耐著性子說道: 請告訴我你的id。\n"); //return 指符合條件的if才會往下判斷
  if( who->query_temp("有向瀧山護法報告") ) //if 中的第二個if
    return notify_fail("瀧山護法不耐煩說道: 煩！你不用對我說這麼多次, 你的id是"+getuid(who)+"，沒錯吧？\n"); //從if中跳出來
  who->set_temp("有向瀧山護法報告",1);
  command("say 快進去吧，記得見到盟主或門派的前輩們要記得問好。\n");
  return 1;
}

string do_help()
{
  object guard;
  if (!ob->query_temp("have_summon")) //設定在npc身上 已經招喚過的就別招喚了 可解決無限召喚的問題
  { //第二隻卻有些裝備尚未著裝 暫時不調整 就當是福利吧 by blazakira
    command("say 在此鬧事，你是嫌命長呀！");
    say("瀧山護法招來他的同伴幫忙抵擋敵人。\n");
    guard=new(__DIR__"b9_fighter.c");
    guard->set_temp("have_summon",1);
    guard->move( environment() );
    guard->kill_ob( ob->query_enemy()[0] );
    ob->set_temp("have_summon",1);
    return "瀧山護法喝道：來人啊..給我上..\n";
  }
}

void greeting(object who)
{
  if( !is_fighting() && !who->query_temp("quests/bonze/fight") && !who->is_fighting() ) //此為殺聯盟成員的mark
  {
    if( who->query_temp("有向瀧山護法報告") == 1 ) //|| wizardp(who) ) //暫時關閉以待測試 by blazakira
    {
      if( who->query("family/family_name")=="瀧山派") //瀧山弟子對於瀧山派之人有好感
      {
        command("ok "+getuid(who) );
        command("say "+RANK_D->query_respect(who)+"，本次聯盟獎勵豐富，你一定沒問題的啦。 :)");
      }
      else if (who->query("class")=="bandit" )
      {
        message_vision("護法弟子一見到來人竟是惡人谷來的，不由得怒上心頭。\n",who); //瀧山弟子對於惡人谷的厭惡
        command("pk2 "+who->query("id"));
        command("say 哼！哪裡來的"+RANK_D->query_respect(who)+"也想參加本盟，最好是滾到一邊涼快去。");
      }
      else if (who->query("class")=="bonze" )
      {
        command("snort "+getuid(who) ); //瀧山對於少林的觀感
        command("say "+who->name()+"前方風雲際會、強者雲集，你…小小地少林派的弟子可不要亂來。");
      }
      else
      {
        command("smile "+getuid(who) ); //瀧山對於其他人的觀感
        command("say "+who->name()+"好，歡迎參加本次十大門派聯盟。 :)");
      }
    }
    else {
      command("stare "+getuid(who));
      command("say 站住！這位"+RANK_D->query_respect(who)+"，來此所為何事？先報上(report)名來。");
    }
  }
  else if ( who->query_temp("quests/bonze/mob") ==1 ) { remove_call_out("greeting"); } //將是否為npc的判斷獨立出來
  else if ( who->query_temp("有向瀧山護法報告") == 1 ) //補上有否報告的判斷
  {
    if (who->query_temp("quests/bonze/greet") < 3) { //有report之後的動作 //加上打招呼的累計判斷
      command("say 這位"+RANK_D->query_respect(who)+"在裡面可別亂來呢。");
      who->add_temp("quests/bonze/greet",1); //打招呼用的次數
    }
  }
  else { //殺了聯盟成員之後所引起的仇視
    command("say 口亨！這位"+RANK_D->query_respect(who)+"先報上(report)名來，這可不是閒雜人等都能進入的。");
    command("pk3 "+getuid(who));
  }
}

int accept_kill(object who)
{
  object ob,guard;
  ob=this_object();
  guard=present( "guard fighter 2",environment(ob) );
  who->set_temp("quests/bonze/fight", 1 ); //在玩家身上紀錄
  command("say 大膽"+who->query("name")+", 竟敢擅闖聯盟駐地！");
  command("wield fireger");
  command("wear all");
//  kill_ob(who);
//應該不論kill or fight 只要設定成一個 其他圍攻的npc 統統下fight好了 這樣比較容易
  if( !present( "guard fighter 2",environment(ob)) || !living(guard)) return 1;
  else {
    tell_room(environment(who),HIR+ob->name()+HIR+"大吼：有人找碴！並肩上！\n"NOR);
    message_vision(HIY"\n瀧山護法看到有人要硬闖，馬上向$N攻過來！\n"NOR,who);
    guard->kill_ob(who);
    return 1;
  }
}

//惡搞：大俠你等等，我先運一下功……//運護身勁
int accept_fight(object who)
{
  who->start_busy(3);
  message_vision("護法弟子急忙地對你說：大俠你等等，我先運一下功\……\n",who); 
  message_vision("護法弟子紮了馬步大喝：哼哼哈兮 ，看我的"HIR"烈焰浩氣\n\n"NOR,who); 
  command("perform haoforce.kang_power");
  command("cough");
  command("cough");
  command("cough");
  message_vision("護法弟子摀著胸口一臉費力的對你說 : 對不起，看起來我無法陪你玩了。\n",who); 
  return notify_fail("\n");
  return 1; //這個return 還是上個return 是無效的吧？
}

string firef()
{
  command("perform haoforce.kang_kee");
  return "\n";
}

void heart_beat()
{
  object me=this_object();
  int maxkee; //maxkee為紀錄玩家max_kee的存量
  maxkee=me->query("max_kee",1);
//自己補血的設定
//將影響的機率分別計算 戰鬥中與 非戰鬥中 且不能暈倒 暈倒還自補 那就搞笑哩XD
  if (is_fighting() && me->query("kee") < maxkee*0.3 && me->query_temp("unconcious") != 1 && (random(100) < 20))
  {
    tell_room(environment(), name()+"氣喘噓噓地咬碎一粒大還丹。\n");
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
  if (!is_fighting() && this_object()->query_temp("count_down") > 1770) //由於本npc為顧門口的 所以延長時間為兩倍
  {//心跳一次 1:1.5(秒)==>1.5x40=1min, 15min=1.5x40x15=900 //縮短為10分 因為在沒有玩家經過或者存在時 心跳功能會停止
    message_vision (HIY"$N見到小兵送來上級的手令，於是轉身飛奔離去，消失在你的眼前。\n"NOR, this_object());
    destruct(this_object());
    return 1;
  } //此括號仍為判斷是否在戰鬥中的if下引號
  return ::heal_up();
}
