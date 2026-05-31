//更改收到東西的判斷方式 以避開學不到靈鷹的邏輯誤判 by blazakira 2010/10/8

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string magic1();
string magic2();
string magic3();
string magic4();
string adv_taoist();
//冰雪風暴之謎 by nike
string love_sky();
string why_sigh();
string butter_fly();
string ice_spell();

string do_area();
string do_array();
string do_howgo();
string ask_tesin();
string ask_tesin2();
string ask_god();
string ask_blood_king();
string do_mission();
string do_area1();
string ask_scroll();
string ask_control();

void create()
{
  set_name("陸清風",({"master lu","master","lu"}));
  set("long", 
"天道紫玄觀的掌門，兩鬢斑白，一對長眉垂頰。看來歲數應該
不少了，但臉上卻依然神采奕奕，到十足像個三四十歲的中年
人。據說他不但精通"HIG"易經"NOR"，"HIG"老莊"NOR"，而且還擅於"HIG"星象"NOR"卜卦一類。\n"
);
       
  set("gender","男性");
  set("class","taoist");
  set("nickname",MAG"紫玄老道"NOR);
  set("combat_exp",3000000);
  set("attitude","friendly");
  set("age",88);
  set("title","天道派掌門人");
  set("str",20);
  set("cps",30);
  set("cor",25);
  set("per",25);
  set("int",35);
  set("con",25);
  set("spi",25);
  set("kar",40);
  set("max_s_kee",100);
  set("s_kee",100);
  set("sec_kee","tiger");
  set("max_kee",10000);
//  set("kee",10000);
  set("max_sen",10000);
//  set("sen",10000);
  set("max_gin",10000);
//  set("gin",10000);
  set("force",5000);
  set("inquiry",([
    "先天乾坤功\正卷" : (:ask_scroll:),
    "有情天"          : (:love_sky:),
    "嘆氣"            : (:why_sigh:),
    "小蝶"            : (:butter_fly:),
    "冰封秘咒"        : (:ice_spell:),
    "星象"            : (:do_area:),
    "雲龍陣"          : (:do_array:),
    "鎖妖塔"          : (:do_howgo:),
    "失落天書"        : "當年眾妖大鬧人間的時失落的，現也不知流落何方。",
    "易經"            : "你去集書房找你筑依師姊要一本來研讀吧。",
    "老莊"            : "集書房裡藏有幾冊翻本，可以去找你筑依師姊要來讀讀。",
    "六芒星魔法陣"    : "這種問題還需要問人喔!?你真是太令我失望了。",
    "血魔"            : (:ask_blood_king:),
    "神聖俠"          : (:ask_god:),
    "逍遙子"          : "逍遙子在大戰中耗力甚大..故聽仙師說..大戰後已遭血魔餘孽圍勦..但我想這麼憑其身手...應該不會如此容易就被擊敗...",
    "天門奇陣"        : "我曾聽師父說過,天門奇陣是當今武林中最神奇的一個陣法,據說是利用
幾把神兵及幾個功\力深厚的人所設的..不過..我也只聽過...不曾有幸見到.",
    "龍鐵心"          : (:ask_tesin:),
    "一面之緣"        : (:ask_tesin2:),
    "使命"            : (:do_mission:),
    "崑崙仙境"        : (:do_area1:),
    "大劍師"          : "這是世人對擁有超強實力並可自行製作武器之人的稱號...
據我所知..目前似乎只有-龍鐵心-擁有此封號.",
    "進階術士"        : (:adv_taoist:),
    "控屍之術"        : "目前最了解此術的師兄已經趕屍出門很久了，到現在還沒回來，此術我也不太熟悉如何使用。",
    "控屍術"          : "目前最了解此術的師兄已經趕屍出門很久了，到現在還沒回來，此術我也不太熟悉如何使用。",
    "師兄"            : "你是說正英師兄啊 ... ",
    "林正英"          : "你是說正英師兄啊 ... ",
    "正英師兄"        : (: ask_control :)
  ]));
  set("chat_chance",3);
  set("chat_msg", ({
    "陸清風緩緩的唸道：「有情天外...無情人...郎心已許\...苦蝶魂」\n",
  }));
  set("max_force",5000);
  set("max_mana",3000);
  set("mana",3000);
  set("atman",3000);
  set("max_atman",3000);
  set("mana_factor",60);
  set_skill("literate",40);
  set_skill("cure",90);
  set_skill("taoism",90);
  map_skill("cure","taoism");
  set_skill("force",60);
  set_skill("gforce",100);
  map_skill("force","gforce");
  set_skill("dodge",80);
  set_skill("g-steps",100);
  map_skill("dodge","g-steps");
  set_skill("magic",100);
  set_skill("gmagic", 100);
  map_skill("magic", "gmagic");
  set_skill("whip",105);
  set_skill("gwhip",100);
  map_skill("whip","gwhip");  
  set_skill("parry",70);
  map_skill("parry","gwhip");
  set_skill("spells",120);
  set_skill("necromancy",100);
  map_skill("spells","necromancy");
  set_skill("move",80);
  map_skill("move","g-steps");
  set("spells/feeblebolt/level",90);
  set("spells/missible/level",100);
  set("spells/hardshell/level",90);
  set("spells/invocation/level",100);
  set("spells/godfight/level",70);
  set("spells/stopmove/level",1);
  set("spells/lightfire/level",1);
  set("spells/flee/level",60);
  set("spells/manabody/level",1);
  set("force_factor",10);
  set("guild_master",1);
  set("marks/god-kee",1);
  set("chat_chance_combat",200);
  set("chat_msg_combat",({
    (: magic1 :),
    (: magic2 :),
    (: magic3 :),
    (: magic4 :),
  }));
  setup();
  create_family("天道派",2,"掌門人");
  carry_object("/open/tendo/obj/red_dragon_chain")->wield();
  carry_object("/open/tendo/obj/lucloth")->wear();
  carry_object("/open/tendo/obj/luboot")->wear();
  add_money("gold",20);
}

void init()
{
  ::init();
}

void greeting()
{
  object user = this_player();
  if(user->query_temp("find_scroll") == 2)
  {
    command("hmm");
    command("say 事不宜遲，我們趕快討論貴教武學寶典的下落吧!!");
  }
  return;
}

int accept_object(object me, object obj)
{
  string object_name; //物品的名稱
  object_name=obj->query("name"); //分為兩段函數作判斷
  switch(object_name) { //判斷收到物品的name
  case "天書":
    if( !obj->query("true") )
    {
      command("angry ");
      command("say 別想拿假的天書來蒙騙我。");
      return 1;
    }else{
      command("pat "+getuid(me));
      command("say 太好了, 是你從冥殿修羅的身上拿回來的嗎﹖謝了。");
    }

    if( me->query("family/family_name") == "天道派" && !me->query("marks/god-kee") )
    {
      command("say 既然你尋獲天書有功\，我便將此天書上所記載的絕學傳授與你吧。");
      write(me->query("name")+"照著陸清風所說的口訣隨手演練一遍。\n"+
        "你覺得心中疑慮豁然貫通, 全身內力迅速流轉一周天。\n"+
        "你學會了天書中所記載的絕學「天罡\戰氣」。\n"+
        "使用方式為「cast godfight」，據聞為一傷敵也傷己身之招式，慎用之。\n");
      me->set("marks/god-kee",1);
      me->set("title",HIY"天道"HIR"嫡傳弟子"NOR);
    }
    break;

  case HIR"焚天魔王的人頭"NOR:
    command("spank "+getuid(me));
    command("say 感謝少俠為武林除害。");
    if( me->query("family/family_name") == "天道派" &&
        (int)me->query("combat_exp")>=5000000 &&
        !me->query("quest/have_hawk") &&
        me->query("quest/ask_tendo_hawk1")==1 )
      {
        command("say 想我天道派與魔界征戰數年，如今終於雨過天晴，得以太平。");
        command("say 就讓為師送你去崑崙仙境拜見祖師爺吧。");
        me->move("/open/tendo/room/b1");
      }
    break;
  default : 
    command("? "+getuid(me));
    break;
  }
  destruct(obj);
  return 1;
}

string love_sky()
{
  object me = this_player();
  if(me->query("class")!="taoist")
    return "你不是本門弟子問這幹什麼？";
  if(me->query("combat_exp") < 5000000) return 0;
  if(!me->query_temp("icestorm/love_sky"))
  {
    command("sigh");
    me->set_temp("icestorm/lovestory",1);
    return "嗯...這...有情天...唉～～";
  }
}

string why_sigh()
{
  object me = this_player();
  if(me->query_temp("icestorm/lovestory")==1)
  {
    command("sob");
    command("say 這你有所不知啊...想當年小蝶情深義重...而我竟辜負了她...");
    me->set_temp("icestorm/lovestory",2);
    return "一切都是我對不起她啊...\n";
  }
}

string butter_fly()
{
  object me = this_player();
  if(me->query_temp("icestorm/lovestory")==2)
  {
    command("sigh");
    command("say 歲月催人老...沒想到這段往事都已經過了六十多年了...");
    command("say 想當年小蝶和老夫從小青梅竹馬，早已私定終生...");
    command("say 無奈家人的不贊成，令我們兩人憤而決定一同出家，發誓十年之內決不婚娶...");
    command("say 於是我們約定好了十年後在長白山芙雪涯相見，一同還俗成親...");
    command("say 但老夫卻...卻早已違背了誓言...偷偷的還俗與另一名女子完成婚約...");
    command("say 不知情的小蝶竟...竟痴痴的在芙雪涯等老夫...");
    command("say 等到老夫赫然想起之時，匆匆趕到芙雪涯卻為時已晚...");
    command("say 小蝶竟為了等老夫而被她師父懲罰，給變成了一座雕像...");
    command("say 以老夫當時的修為，根本無法破解這殘酷的「冰封秘咒」...");
    command("say 老夫從此便下定決心，一心向道，永不婚娶，並將芙雪涯改名為有情天...");
    command("say 雖然事隔多年，但直到今日，老夫還是沒有勇氣去面對小蝶...");
    command("sigh");
    me->set_temp("icestorm/lovestory",3);
    return "事情始末便是如此...";
  }
}

string ice_spell()
{
  object me = this_player();
  if(me->query_temp("icestorm/lovestory")==3)
  {
    command("say 這殘酷的古術書早已消失在世界上...");
    return "但老夫當年趕到芙雪涯時，詢問過一名獵狩，他說有見到一名老道姑上山而去，
卻不知所謂何事，只知道其手上拿著一本破書";
  }
}

string do_mission()
{
  object who=this_player();
  if(who->query("class")!="taoist")
    return "你不是本門弟子問這幹什麼？";
  if(who->query_temp("ask_area1")!=1)
    return "這不是妳該問的吧";
  who->set("quest/ask_tendo_hawk1",1);
  return HIY"\n            當年魔王焚天禍害人間，先師便發誓要鏟除焚天維護天下和平，如今\n            你取來焚天魔王的人頭，為師便幫你解除『異域空間』。"NOR;
}

string adv_taoist()
{
  object me=this_player();
  int i;
  i=random(3);
  if(me->query("class")!="taoist")
    return "奇怪, 妳不是本派之人,問那麼多幹嘛...";
  if(me->query("adv_taoist"))
    return "你已經是了還問??";
  if(me->query("combat_exp") < 3000000 )
    return "你的經驗還太淺薄了, 多加磨練後再來找我吧...";
  if(me->query("spells/feeblebolt/level")<100)
    return "你的蒼冥之箭還不夠強, 不夠資格";
  if(me->query("spells/missible/level")<100)
    return "你的紫幽之箭還不夠強, 不夠資格";
  if(i==0){
    me->set("title",HIR"三道魂"HIW"˙"HIG"冥月"HIM"道使"NOR) ;
    message("system",HIG"陸清風朗聲說道:恭喜"HIY+this_player()->name()+HIM"成為"HIR"三道魂"HIW"˙"HIG"冥月"HIM"道使..\n"NOR,users());
  } 
  else if(i==1){
    me->set("title",HIR"三道魂"HIW"˙"HIR"焰日"HIM"道使"NOR) ;
    message("system",HIG"陸清風朗聲說道:恭喜"HIY+this_player()->name()+HIM"成為"HIR"三道魂"HIW"˙"HIR"焰日"HIM"道使..\n"NOR,users());
  }
  else{
    me->set("title",HIR"三道魂"HIW"˙"HIC"銀星"HIM"道使"NOR) ;
    message("system",HIG"陸清風朗聲說道:恭喜"HIY+this_player()->name()+HIM"成為"HIR"三道魂"HIW"˙"HIC"銀星"HIM"道使..\n"NOR,users());
  }
  me->set("adv_taoist",1);
  return "恭喜你,修為更上層樓並對於紫幽及蒼冥之箭有更深的造詣!!";
}

void attempt_apprentice(object ob)
{
  object whip;
  if(this_player()->query("class")!="taoist")
  {
    command("say 你我志向不同，還是另尋名師吧。\n");
    return;
  }
  if(this_player()->query_kar() < 25)
  {
    command("say 你我有緣無份，還是另尋名師吧！\n");
    return;
  }
  command("hmm");
  command("recruit "+ob->query("id"));
  message("system",HIG"陸清風撫鬚笑道『  乘天地之正，御六氣之辯  』

悠悠寰宇中，又多了一位仙風道骨的術士！！\n"NOR,users());

  command("say 本派首重修身養性，非不得已盡量不要與人交手。");
  write("\n");
  command("hmm");
  command("say 你可以先去找志清師叔買件修行用的道服。");
}

string do_area1()
{
  object who=this_player();
  if(who->query("class")!="taoist")  
    return "你不是本門弟子問這幹什麼？";
  who->set_temp("ask_area1",1);
  return HIY"\n            當年先師為了防止有人闖入崑崙仙境擾他清修，特別在入口之處佈置\n            無上道法『異域空間』，並吩咐若想前往崑崙仙境，必先完成天道派\n            宿世使命，方能獲准進入仙境。"NOR;
}

string do_area()
{
  object who=this_player();
  if(who->query("class")!="taoist")
    return ("哎....星象之學浩瀚無窮，豈是三言兩語就能說完的。");
  return ("說到星象，這"HIW"雲龍陣"CYN"就是為師當年以星象為據所排出的迷陣。"NOR"");
}

string ask_tesin()
{
  if( this_player()->query("quests/shasword")==2) {
    return("大劍師龍鐵心..我曾與他有一面之緣..但由於當時我年歲尚輕..因此無法向其請教!"); }
}

string ask_tesin2()
{
  if( this_player()->query("quests/shasword")==3) {
    this_player()->set("quests/shasword",3);
    return(" 我當時正經過魔域,正好龍鐵心在鑄劍.由於靈氣逼人.我循氣而行,因而有幸得見傳說中的大劍師!"); }
}

string ask_blood_king()
{
  if (this_player()->query("quests/shasword")==2) {
    return ("百多年前.血魔擾亂武林..仙劍祖師消遙子帶領當初極富盛名的刀神.儒俠三人出面勦魔.之後血魔就消聲匿跡.但消遙子與神聖俠亦消失無蹤了."); }
}

string ask_god()
{
  if (this_player()->query("quests/shasword")==2) {
    this_player()->set("quests/shasword",4);
    return ("這神聖俠..據說是當初實力最強的三人了.."); }
}

string do_array()
{
  object who=this_player();
  if(who->query("class")!="taoist") {
    return ("你不是本門弟子問這幹什麼？");
    who->move("/open/trans/room/room4"); }
  if(!who->query_temp("asked")) {
    who->set_temp("asked",1);
    return ("\n也好....你既然成為術士，也該知道這事。\n\n陸清風略有所思地繼續說道﹕
在雲龍陣旁有座"HIW"鎖妖塔"CYN"。是當年魔界出口--魔眼洞崩毀眾妖大鬧人間
時，被祖師爺封印於那的。由於眾妖危害甚巨，為師才特地佈陣於此
加以保護，以防節外生枝壞了祖師爺五百年前的一番浴血苦戰。"NOR"");
  }
  return ("\n此陣殺惡不殺善，是專防妖魔侵入而設。如殺氣過高則陣中雲龍會誤以為妖魔來
襲而攻擊。

接著陸清風語帶雙關地說道﹕
此陣更分為正逆兩儀，由八卦衍生而出，正行可到天道紫玄道觀這裡，逆行可致
魔妖，切記切記。");
}

string do_howgo()
{
  object who=this_player();
  if(who->query("class")!="taoist")
    return ("此事乃本門機密，"+RANK_D->query_respect(who)+"不必多問了。");
  return ("\n
這鎖妖塔的妖怪厲害異常，就算是當年，祖師爺也費了九牛二虎之力
才將其封住。其中有一隻強力妖怪由鎮塔明王守著!!");
}

int accept_fight (object who)
{
  command("conj hardshell");
  return 1;
}

int accept_kill(object who)
{
  who=this_player();
  kill_ob(who);
  command("conj hardshell");
  command("say 施主既執意如此,休怪貧道手下無情了!!");
  return 1;
}

string magic1()
{
  if(this_object()->query("kee")<=8000)
  {
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
  if(random(3)<=2)
  command("cast stopmove");
  return "\n";
}

string magic4()
{
  command("cast godfight");
  return "\n";
}

void die()
{
  object cloth;
  int j;
  object winner = query_temp("last_damage_from");
  string name,class1;

  if(!winner)
  {
    ::die();
    return ;
  }
  name = winner->query("name");
  class1 = winner->query("family/family_name");

  new("/open/tendo/obj/lucloth")->move(winner);
  tell_object(users(),HIW"          
         陸清風"HIG"嘆道:"HIC"天書"HIG"尚未找回,"HIR"冥殿修羅"HIG"未敗,
                    哎,我竟會敗給"+HIB+class1+HIG"弟子"+HIB+name+HIG+"之手,
                    我不干心阿!!\n\n
              "HBCYN"一道白光從崑崙山直升天際\n"NOR);
/*
  if(userp(winner) && winner->query_temp("not_robot") > 1 )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {      
        new("/open/sky/obj3/light_feather")->move(environment(winner));
        message_vision(HIM"\n從陸清風的身上掉下了一件奇怪的東西!!\n"NOR,winner);
        write_file("/log/sky/obj3/light_feather",sprintf("%s(%s) 讓陸清風掉下了光之明羽於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    }else{
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {      
        new("/open/sky/obj3/light_feather")->move(environment(winner));
        message_vision(HIM"\n從陸清風的身上掉下了一件奇怪的東西!!\n"NOR,winner);
        write_file("/log/sky/obj3/light_feather",sprintf("%s(%s) 讓陸清風掉下了光之明羽於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  } */
  ::die();
}

string ask_scroll()
{
  object me = this_player();
  if(me->query_temp("find_scroll") >= 2)
  {
    me->set_temp("find_scroll",3);
    return "先祖知道這武技具有毀天滅地之威，為免落入邪道手中，臨終前
            以畢生法力將其封印於六芒星魔法陣的陣眼，並設下護衛把守，
            傳說唯有身負洛書河圖武學的人才有資格進入取書，你既然尋回
            洛書系失落的渾天水晶，又身負河圖系的先天乾坤功\基礎，自是
            取得此書的最佳人選，現在立刻出發吧!!本派將派人暗中相助。\n";
  }
  command("snort");
  return "你還不夠格跟我討論這事兒。";
}

string ask_control()
{
  object me = this_player();
  if(me->query("class") != "taoist")
    return "嗯，本門派的事，本門派會解決。";
  if(me->query("quest/control"))
    return "感謝你把師兄找回來，想必你已經學會控屍術了吧。";
  if(me->query_temp("control"))
  {
    return "快去把師兄找回來吧。";
  }
  me->set_temp("control",1);
  return "正英師兄在幾個月前趕屍出門，預計要在上個月就要回來了，可是到目前為止還沒回來，真不知道他已經到哪裡去了…\n";
}
