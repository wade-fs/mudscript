// master_death.c by babe
//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/1/9

#include <ansi.h>
inherit NPC;

string spiritism();
string ask_spirit();
string ask_spirit2();
string ask_spirit3();
string ask_spirit4();
string ask_spirit5();
string ask_blade();

void create()
{
  set_name( "老不死", ({ "master death", "master", "death" }) );
  set( "title", "墳場老者" );
  set( "nickname", HIB"太歲"NOR );
  set( "gender", "男性" );
  set( "age", 1000 );
  set( "attitude", "hero");
  set( "long",
    "    老不死的臉容枯\瘦凹陷, 比鐵更加冰冷堅硬, 而且\n"
    "沒有眼珠, 但眼眶內卻黑沉沉, 似隱藏著無盡凶惡, 散\n"
    "發著無比濃烈的死亡氣息。\n"
    "    老不死當年以一招「御魂術」稱霸武林, 並得以長\n"
    "生不老, 但現在不知為何隱居於此。\n\n" );
  set( "combat_exp"  , 20000000 );
  set( "max_kee"     , 15000 );
  set( "max_force"   , 10000);
  set( "force"       , 10000);
  set( "force_factor", 10 );
  set( "no_lyssa", 1 );
  set( "chat_chance" , 10 );
  set( "chat_msg", ({
    (: command ("say 閒雜人等快滾吧!") :),
    (: command ("say 看什麼看!") :),
    (: command ("say 走開走開!") :),
    (: command ("say 給我滾!") :),
    (: command ("say 滾開!") :),
    (: command ("say 滾!") :),
    (: command ("say 叫你滾還不滾?") :), 
    (: command ("say 正道人士都是一群烏龜王八蛋!") :), 
    (: command ("say 叫你滾還不滾?") :), 
    (: command ("spit") :),
    (: command ("yawn") :),
    }) );
  set("inquiry",([
    "刀"           : (: ask_blade :),
    "可惜"         : (: ask_spirit :),
    "神屬靈魂"     : "傳聞眾多古神中有些很倒楣的遭遇意外而導致靈魂破碎的情形發生。\n",
    "靈魂碎片"     : "目前我所知道的是前輩「神農氏」為蒼生嘗百草所積累的因果，不知為何使得上天降下\n"+
         "            九九八十一道天劫，本來此等善果必定能夠渡劫成功\。但是他莫名失敗了——\n"+
         "            由於他渡劫失敗，但是因他早年治療眾生所累積的福報，使得眾多仙人傾力相助，雖得\n"+
         "            保持靈魂不滅，但是卻也支離破碎因而四散各處。目前已知尚有五個靈魂碎片被人持有\n"+
         "            著。\n",
    "五大王者"     : "當今的五大王者呀…\n\t「"HIR"魔界之王"CYN"」焚天魔王、\n\t「"BLU"玄冥魔神"CYN"」死靈骨魔、\n\t「"HIR"煉獄蛇王"CYN"」蛇郎君、\n\t「"HIR"火之王者"CYN"」火龍王、\n\t「"HIY"龍神"CYN"」海皇等這五位。",
    "抵抗惡靈"     : "笨蛋，惡靈最怕的當然就是我，我號稱"HIC"三才子"CYN"耶，這還要問。\n",
    "靈魂碎片組合" : (: ask_spirit2 :),
    "組合\碎片"    : (: ask_spirit3 :),
    "生之力"       : (: ask_spirit4 :),
    "除非"         : (: ask_spirit5 :),
    "儀式"         : "看看我另個稱號再想想你從華陀醫術中學到什麼，這樣還猜不出來那你就乖乖被惡靈騷擾吧。\n",
    ]));
  setup();
}

void init()
{
  object me=this_player();
  if( !query_heart_beat(this_object()) )
    set_heart_beat(1);
  set( "chat_chance" , 10 );
  environment()->set("no_transmit",1);
  add_action("do_accept","accept");
  add_action("do_unaccept","unaccept");
  add_action("do_answer","answer");
  ::init();
}

int accept_fight( object who )
{
  object me = this_object();
  command( "say 找死!!!\n" );
  message_vision( HIR"$N祭起頂級"RED"御魂術"HIR", 臉孔陡變透明, 地底不斷竄出無數邪靈。\n\n"NOR, me );
  message_vision( HIR"霎時間怒吼與狂嘯聲不絕, 震得人耳鼓欲破。\n\n"NOR, me );
  message_vision( HIR"$N被邪靈團團圍住, 瞬間便被啃蝕殆盡, 恐怖駭人。\n\n"NOR, who );
  tell_object( who , "你的眼前一片黑暗......\n" );
  who->remove_all_killer();
  who->unconcious();
  load_object( "/open/trans/room/room4" ); //改為新位置
  who->move( "/open/trans/room/room4" );
  return 1;
}

int accept_kill( object who )
{
  object me = this_object();
  command( "say 找死!!!\n" );
  message_vision( HIR"$N祭起頂級"RED"御魂術"HIR", 臉孔陡變透明, 地底不斷竄出無數邪靈。\n\n"NOR, me );
  message_vision( HIR"霎時間怒吼與狂嘯聲不絕, 震得人耳鼓欲破。\n\n"NOR, me );
  message_vision( HIR"$N被邪靈團團圍住, 瞬間便被啃蝕殆盡, 恐怖駭人。\n\n"NOR, who );
  tell_object( who , "你的眼前一片黑暗......\n" );
  who->remove_all_killer();
  who->unconcious();
  load_object( "/open/trans/room/room4" );
  who->move( "/open/trans/room/room4" );
  return 1;
}

int accept_object(object who, object ob)
{
  string object_id;
  object_id=ob->query("id");
  switch(object_id) {
  case "spirit blade" :
    command("say 很好，你還算是個守信用之人。");
    destruct(ob);
    if (who->query_temp("quests/doctor_book/ask2") == 1)
    {
      who->set_temp("quests/doctor_book/ask2",2);
      tell_object(who,HIY
        "老不死接著說﹕還有一件事情要先跟你說，由於結合靈魂是屬於逆天的行為，上天不容\n"+
        "              許\這種事情發生，因此將會有天劫降下來懲罰你，如果說你的實力不足\n"+
        "              那麼逆天而行的你將會魂飛魄散，你確定你準備好要開始結合靈魂時再\n"+
        "              跟我說。(answer yes/no)\n"+NOR);
    }
    return 1;
    break;
  default : break;
  }
  command("say 見鬼了，我這可不是垃圾堆呀！想死一遍試試看嗎？");
  return 1;
}

void greeting(object obj)
{ //拒絕(unaccept)了 就根據房間紀錄的參數來判斷 漠視這位玩家吧(笑
  if( obj->query_temp("quests/doctor_book/check") && !obj->query_temp("quests/doctor_book/ask") && !environment()->query_temp("quests/doctor_book/unaccept_id/"+obj->query("id")) )
    if( present("spica soul splinters",obj) || present("kui soul splinters",obj) ||
        present("jing soul splinters",obj) || present("star soul splinters",obj) ||
        present("lin soul splinters",obj) ) { //如果遇到的玩家持有關鍵道具 且並非第一次遇到
      obj->set_temp("quests/doctor_book/ask",1);
      do_command("arc "+obj->query("id"));
      tell_object(obj,HIY"老不死說道﹕你身上竟然有神屬靈魂，但支離破碎，可惜……\n"+NOR);
      set( "title", HIC"靈魂使者"NOR );
    }
//完成五樣靈魂之力的收集 且為銀針門限定
  if( present("spica soul energy",obj) && present("kui soul energy",obj) &&
      present("jing soul energy",obj) && present("star soul energy",obj) &&
      present("lin soul energy",obj) && obj->query("family/family_name")=="銀針門" ) {
//分為 已接受天劫考驗與初次接受 再細分 身上有沒有刀 與 有沒有還刀
    if( !obj->query("quest/doctor_book/godthunder") && present("spirit blade",obj) ) {
      do_command("pat "+obj->query("id"));
      obj->set_temp("quests/doctor_book/ask2",1);
      tell_object(obj,HIY
        "老不死說道﹕你終於蒐集完畢了，刀先還給我吧。作人要有誠信，不過你想留著也沒關係。\n"+
        "            我現在要幫你結合，但是在過程中需要你的全力配合，如果你內功\沒達到一定\n"+
        "            程度，可是無法將靈魂碎片結合，這點你得先注意。\n"+NOR);
    }
    else if( !obj->query("quest/doctor_book/godthunder") && !present("spirit blade",obj) ) {
      do_command("pat "+obj->query("id"));
      obj->set_temp("quests/doctor_book/ask2",2);
//      this_object()->init(); //會產生無限循環的init()->greeting()->init().....
      tell_object(obj,HIY
        "老不死說道﹕你終於蒐集完畢了，刀不在你手上？那也沒關係，一把破刀而已。\n"+
        "            我現在要幫你結合，但是在過程中需要你的全力配合，如果你內功\沒達到一定\n"+
        "            程度，可是無法將靈魂碎片結合，這點你得先注意。\n"+
        "            準備好了再跟我說一聲吧。(answer yes/no)\n"+NOR);
    }
    else if(obj->query("quest/doctor_book/godthunder") && present("spirit blade",obj) ){
      do_command("hehe "+obj->query("id"));
      obj->set_temp("quests/doctor_book/ask2",1);
      tell_object(obj,HIY
        "老不死說道﹕桀桀～你以為渡劫這麼簡單嗎，那可是天劫耶！上天之威豈容凡人褻瀆。\n"+
        "            不過你在渡劫之前先將刀還我吧，那剃牙還不錯用呢，嘎嘎…\n"+NOR);
    }
    else {
      do_command("hehe "+obj->query("id"));
      obj->set_temp("quests/doctor_book/ask2",2);
      tell_object(obj,HIY
        "老不死說道﹕桀桀～你以為渡劫這麼簡單嗎，那可是天劫耶！上天之威豈容凡人褻瀆。\n"+
        "            準備好了再跟我說一聲吧。(answer yes/no)\n"+NOR);
    }
  }
}

string spiritism()
{
  object me, who;
  string g, respect;

  me = this_object();
  who = this_player();
  g = who->query("gender")=="男性" ? "你": "妳";
  respect = RANK_D->query_respect(who);

  if( !who->query("pker") ) {
    if( who->query("spiritism/0")==1 ) {
      command( "say 嘿, 徒兒這回帶些什麼好東西來孝敬為師啊?" );
      return "";
    }
    if( who->query_temp("spiritism")==1 ) {
      switch( random(5) ) {
      case 0 :
        command( "say 快滾!" );
        break;
      case 1 :
        command( "say " + respect + "還死賴在這裡幹嘛?" );
        break;
      case 2 :
        command( "say 滾開!" );
        break;
      case 3 :
        command( "say " + respect + "若再不快滾, 休怪老夫不客氣了!" );
        break;
      default :
        command( "say 滾!" );
      }
      return "";
    }
    command( "look "+who->query("id") );
    if( who->query_cor()< 20 ) {
      switch( random(2) ) {
      case 0 :
        who->do_command("cower");
        command( "say 哼! 老夫只瞧得起有膽識的人。" );
        who->do_command("cower");
        command( "say " + g + "好好看看" + g + "自己! 現在都已嚇成什麼樣子了。" );
        command( "say 還是快滾吧。" );
        who->do_command("flee");
        break;
      default :
        who->do_command("cower");
        me ->do_command("? "+who->query("id"));
        command( "say 哼! 就憑" + g + "這種貨色也想修習此術? 哈!" );
        who->do_command("cower");
        command( "say " + g + "好好看看" + g + "自己! 現在都已嚇成什麼樣子了。" );
        command( "say 還是快滾吧。" );
        who->do_command("flee");
      }
      who->set_temp( "spiritism", 1 );
      return "";
    }
    if( who->query_cor() > 34 ) {
      me ->do_command("hmm");
      command( "say " + respect + "乃難得的奇才。" );
      command( "say 不過還是得證明" + g + "的能力讓老夫瞧瞧。" );
      who->set_temp( "spiritism", 1 );
      return "";
    }
    switch( random(2) ) {
    case 0 :
      command( "say 老夫只看得起有膽識的人。" );
      command( "say 等" + respect + "敢殺人時再來找我吧。" );
      break;
    default :
      command( "say 修習此術需有過人膽識。");
      command( "say 老夫瞧" + respect + "並不適合修習此術。" );
      command( "say 還是滾一邊涼快去吧。" );
    }
    who->set_temp( "spiritism", 1 );
    return "";
  }
  if( !who->query_temp("spiritism") ) {
    command( "say 殺人兇手來墓地作什麼?" );
    command( "say 不怕死者找你報仇嗎?" );
    command( "say 快夾著尾巴逃吧! 哈!" );
    return "";
  }        
  message_vision( HIY"\n$N一陣狂笑。\n\n"NOR, me );
  command( "say 很好, 老夫很欣賞" + respect + "。" );
  command( "say 這就傳" + respect + "此術心法, 以免後世無知小輩無幸觀此驚世絕學。" );
  command( "say 老夫先以內力助" + g + "通過此術最為凶險的關卡。" );
  command( "say 當心了!" );
  tell_room( environment(me), HIM + me->query("name") + "運起至陰"RED"御魂術"HIM", 散發出陣陣濃烈的死亡氣息。\n"NOR, who );
  who->set( "spiritism/0", 1 );
  who->unconcious();
  return "";
}

void die()
{
  object  who = query_temp("last_damage_from");
  object  me  = this_object();
  command( "say 找死!!!\n" );
  message_vision( HIR"$N祭起頂級"RED"御魂術"HIR", 臉孔陡變透明, 地底不斷竄出無數邪靈。\n\n"NOR, me );
  message_vision( HIR"霎時間怒吼與狂嘯聲不絕, 震得人耳鼓欲破。\n\n"NOR, me );
  message_vision( HIR"$N被邪靈團團圍住, 瞬間便被啃蝕殆盡, 恐怖駭人。\n\n"NOR, who );
  tell_object( who , "你的眼前一片黑暗......\n" );
        who->remove_all_killer();
        who->die();
  :: die();
}

string ask_spirit()
{
  object me=this_player();
  if(me->query_temp("quests/doctor_book/ask")>0 && me->query_temp("quests/doctor_book/ask")<3)
  {
    command("sigh");
    command("say 可惜阿，你所持有的靈魂碎片是支離破碎的～");
    command("hmm");
    command("say 不過呢，有方法可以讓這個靈魂甦醒，那就是將我手中持有的碎片與這五個靈魂碎片組合。");
    me->set_temp("quests/doctor_book/ask",2);
    return "";
  }
}

string ask_spirit2()
{
  object me=this_player();
  if(me->query_temp("quests/doctor_book/ask")==2 )
  {
    if( present("spica soul splinters",me) && present("kui soul splinters",me) &&
        present("jing soul splinters",me) && present("star soul splinters",me) &&
        present("lin soul splinters",me) ) { 
      command("sigh");
      command("say 難得你蒐集到五片了，我就撥點時間告訴你這不成材的小子如何組合碎片吧。");
      me->set_temp("quests/doctor_book/ask",3);
      return "";
    }
	else {
      command("say 滾遠點！還沒蒐集到五個就敢過來，不想活了呀你！");
      command("pk2");
      return "";
    }
  }
}

string ask_spirit3()
{
  object me=this_player();
  if(me->query_temp("quests/doctor_book/ask")==3 )
  {
    command("haha");
    command("say 既然你有心要恢復銀針門的榮光，憑著我跟華老的交情，幫你一下何嘗不可。");
    command("say 
      要將這個靈魂碎片組合起來，光靠我還不夠，還要需要你的幫忙，這世界有五大王者，而這五大王者身上都
      有強烈的生之力，你需要取出這五大王者所有的生之力來注入這五個靈魂碎片中，使其恢復應有的生之力。\n");
    me->set_temp("quests/doctor_book/ask",4);
    return "";
  }
}

string ask_spirit4()
{
  object me=this_player();
  if(me->query_temp("quests/doctor_book/ask")==4 )
  {
    command("say 
      要取出他們身上的生之力，得需要我手中這把刀的幫助，但這刀的誕生有些離奇，因此對於世人而言是把受
      詛咒的刀，會吸收持有者的生之力，也就是包含持有者在內四周的魂魄，是把雙面刃。
      這刀長期在亂葬崗這邊，並受到太歲我控制，一來使亂葬崗這邊魂魄不至於跑到這世間作惡，二來也填飽此
      刀的慾念，因此若直接交給你，我擔心你壓制不住此刀的刀魂而反遭惡靈附身，除非…\n");
    me->set_temp("quests/doctor_book/ask",5);
    return "";
  }
}

string ask_spirit5()
{
  object me=this_player();
  if(me->query_temp("quests/doctor_book/ask")==5 )
  {
    command("say 
      除非你能找到具有正義之氣並可抵抗惡靈的東西，要不然你會被惡靈附身直到死亡，方法我已經傳授給妳了
      ，你要現在是否要接受此刀嗎？(accept /unaccept )\n");
    me->set_temp("quests/doctor_book/ask",6);
    return "";
  }
}

int do_accept()
{
  object me = this_object(),who = this_player();
  if(who->query_temp("quests/doctor_book/ask")==6)
  {
    if( !present("spirit blade",who) ) {
      new("/open/doctor/doctor_book/obj/spirit_blade_v1.c")->move(who);
      who->apply_condition("spirit_curse",10);
      message_vision("$N給$n一把"+HBYEL+HIW"雙"HIC"界"HIR"刀"NOR"。\n",me,who);
      message_vision(HIR"失去$N控制的"+HBYEL+HIW"雙"HIC"界"HIR"刀"NOR+HIR"瞬間失控，無數邪靈纏繞其上，$n感到有些擔心。\n"NOR,me,who);
    }
    else {
      command( "stare "+who->query("id") );
      command( "say 既然刀在你身上，你該早點用完然後還我啊。" );
    }
    return 1;
  }
}

int do_unaccept()
{
  object me = this_object(),who = this_player();
  if( present("spirit blade",who) ) {
    command( "stare "+who->query("id") );
    command( "say 既然刀在你身上，你該早點用完然後還我啊。" );
    return 1;
  }
  if(who->query_temp("quests/doctor_book/ask")==6)
  {
    command( "say 不成材的懦夫！\n" );
    message_vision( HIR"$N祭起頂級"RED"御魂術"HIR", 臉孔陡變透明, 地底不斷竄出無數邪靈。\n\n"NOR, me );
    message_vision( HIR"霎時間怒吼與狂嘯聲不絕, 震得人耳鼓欲破。\n\n"NOR, me );
    message_vision( HIR"$N被邪靈團團圍住, 瞬間便被啃蝕殆盡, 恐怖駭人。\n\n"NOR, who );
    tell_object( who , "你的眼前一片黑暗......\n" );
    who->remove_all_killer();
    who->unconcious();
    load_object( "/open/trans/room/room4" );
    who->move( "/open/trans/room/room4" );
    environment(me)->set_temp("quests/doctor_book/unaccept_id/"+who->query("id"),1); //避免npc意外身故 紀錄mark在房間中
    who->delete_temp("quests/doctor_book/ask");
    return 1;
  }
//  return 0; //可以忽略 因與預設相同
}

int do_answer(string str)
{
  object ob = this_object(),who = this_player();
  if (!str)
    return 0;
  else if ( who->query_temp("quests/doctor_book/ask2") != 2 )
    return 0;
  else if ( present("ball of Shen Nongshi spirit",who) )
    return notify_fail("滾！快把東西交給華佗。\n");
  else if ( present("spirit blade",who) )
    return notify_fail("先把刀還我吧。\n");
  else if ( str=="no" )
  {
    command("say 既然你還沒準備好，那就繼續保管吧。\n");
  }
  else if ( str=="yes" )
  { //不額外做玩家既有hp的判定 就讓沒準備好的 死一次吧:D
    if ( who->query("combat_exp")<8000000 ) {
      tell_object(who,"你還太稚嫩了，先去鍛鍊一下提昇你的實戰經驗再說吧。拿著刀，對你有好處的。\n");
    }
    else if ( who->query("max_force")<7000 ) {
      tell_object(who,"你的內功\太差，需繼續修煉。刀先拿著，對你修煉之路更有幫助。\n");
    }
    else if ( who->query("force")<7000 ) {
      tell_object(who,"你的內力不足，無法支撐融合靈魂所需。拿著刀，準備好了再來。\n");
    }
    else if ( present("spica soul energy",who) && present("kui soul energy",who) &&
              present("jing soul energy",who) && present("star soul energy",who) &&
              present("lin soul energy",who) ) {
      who->add("force",-7000);
      command("say 準備好了，那就開始吧。");
      set( "chat_chance" , 0 ); //暫時關閉
      tell_object(who,HIW"只見老不死口中唸唸有詞，而你卻一點也不明白其中涵意，難道這就是天界語？這疑問閃過\n"
        "你腦海，但你並未深思，一邊把神農氏靈魂碎片放置手中，屏氣凝神將內力緩緩輸入其中。\n"NOR
        "（承受不住時，可逃離現場，每分鐘一發天劫雷電。）\n");
      call_out("godthunder",1,who);
      return 1;
    }
    else {
      tell_object(who,"東西呢？先拿著刀去收集吧。\n");
    }
  }
  command("grin "+who->query("id"));
  new("/open/doctor/doctor_book/obj/spirit_blade_v1.c")->move(who);
  message_vision("$N給$n一把"+HBYEL+HIW"雙"HIC"界"HIR"刀"NOR"。\n",ob,who);
  message_vision(HIR"失去$N控制的"+HBYEL+HIW"雙"HIC"界"HIR"刀"NOR+HIR"瞬間失控，無數邪靈纏繞其上。\n"NOR,ob,who);
  return 1;
}

int godthunder(object me)
{
  object ob = this_object();
  int i;
  if ( !me || environment(me) != environment(ob) ) {
    set( "chat_chance" , 10 );
    return; //人不在同一間房間就停止
  }
  i=me->query("quest/doctor_book/godthunder");
  if (i==9) call_out("godthunder10",1,me);
  else if (i <9) //有接受過這次的天劫就不需要再打一次了 //這mark為暫存 在任務完成後會刪除
  {
    message_vision(YEL"\n\t（一道閃電從不遠的天上直直的命中$N，$N身上到處都是閃電過後留下的焦痕。）\n"NOR,me);
    me->add("quest/doctor_book/godthunder",1);
    if (me->query("kee") < i*1000+1000)
    {
      message_vision(YEL"\t（$N受到難以承受的重傷之後發出一聲慘叫……）\n\n"NOR,me);
      me->remove_all_killer();
      me->unconcious();
//給予昏迷者死亡的參數:p
      me->set("eff_gin",-100);
      me->set("gin",-100);
      me->set("eff_kee",-100);
      me->set("kee",-100);
      me->set("eff_sen",-100);
      me->set("sen",-100);
    }
    else {
      message_vision(HIG"\t（$N拍拍身上的灰塵，大呼爽快！）\n\n"NOR,me);
      me->receive_damage("kee", i*1000+1000,ob ); //第三個參數為ob=last_damage_from 設為老不死 不然要給天劫一個名稱有點麻煩:p
      me->receive_wound("kee", i*1000+1000,ob );
      call_out("godthunder",30,me);
    }
  }
  else //出現i>9的情況? 是bug吧? 還是邏輯哪裡出錯了?? 反正就重算吧 grin
  {
    me->set("quest/doctor_book/godthunder",1);
    call_out("godthunder",1,me);
  }
}

int godthunder10(object me)
{
  object ob = this_object();
  if ( !me || environment(me) != environment(ob) ) return;
  if (me->query("quest/doctor_book/godthunder")==9)
  {
    if( present("spica soul energy",me) && present("kui soul energy",me) &&
        present("jing soul energy",me) && present("star soul energy",me) &&
        present("lin soul energy",me) ) {
      tell_object(me,"\n老不死看起來由衷感到喜悅﹕銀針門復甦有望了，老友也會相當高興吧。\n"+
        "                          這顆"HIB"神農氏靈魂珠"NOR"你趕快拿去給他。\n");
//      me->delete("quest/doctor_book"); //由於碎片可作裝備升級機率的媒介所以不全部刪除 改為以下逐項刪除
      me->delete("quest/doctor_book/godthunder");
/* 暫時不刪除 也許可以作為二次獎勵的先置限制
      me->delete("quest/doctor_book/Lin_soul_energy");
      me->delete("quest/doctor_book/Sta_soul_energy");
      me->delete("quest/doctor_book/Jing_soul_energy");
      me->delete("quest/doctor_book/Kui_soul_energy");
      me->delete("quest/doctor_book/Spica_soul_energy");
*/
      me->delete_temp("quests/doctor_book/");
      destruct(present("spica soul energy",me));
      destruct(present("kui soul energy",me));
      destruct(present("jing soul energy",me));
      destruct(present("star soul energy",me));
      destruct(present("lin soul energy",me));
      new("/open/doctor/doctor_book/obj/spirit_ball.c")->move(me);
      set( "chat_chance" , 10 );
    }
    else {
      tell_object(me,"\n老不死生氣地對著你說﹕滾！東西沒帶還敢接受測試，去死吧！\n");
      message_vision( HIR"$N祭起頂級"RED"御魂術"HIR", 臉孔陡變透明, 地底不斷竄出無數邪靈。\n\n"NOR, ob );
      message_vision( HIR"霎時間怒吼與狂嘯聲不絕, 震得人耳鼓欲破。\n\n"NOR, ob );
      message_vision( HIR"$N被邪靈團團圍住, 瞬間便被啃蝕殆盡, 恐怖駭人。\n\n"NOR, me );
      tell_object( me , "你的眼前一片黑暗......\n" );
      me->remove_all_killer();
//      me->unconcious();
      load_object( "/open/trans/room/room4" );
      me->move( "/open/trans/room/room4" );
    }
  }
}

string ask_blade()
{
  object me = this_object(),who = this_player();
  if( !present("spirit blade",who) ) {
    new("/open/doctor/doctor_book/obj/spirit_blade_v1.c")->move(who);
    command( "say 喔～你想拿拿看呀，那借你玩玩吧。" );
    command( "grin" );
    message_vision("$N給$n一把"+HBYEL+HIW"雙"HIC"界"HIR"刀"NOR"。\n",me,who);
    message_vision(HIR"失去$N控制的"+HBYEL+HIW"雙"HIC"界"HIR"刀"NOR+HIR"瞬間失控，無數邪靈纏繞其上，$n感到有些擔心。\n"NOR,me,who);
  }
  else {
    command( "stare "+who->query("id") );
    command( "say 既然刀在你身上，你該早點用完然後還我啊。" );
  }
  return "";
}
