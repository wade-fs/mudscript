// master_tor.c made by adam..
// refix by chan
// add quest thing by nike
//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/1/9

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_vet();
string ask_tor();
string ask_savedie();
string ask_lee();
string ask_secret();
string ask_pass(); //給予藏經閣入閣令
string ask_soul()
{
  if(this_player()->query_temp("quests/confuse") < 5) 
  {
    return "你問這個幹嘛？";
  }
  this_player()->set_temp("quests/confuse",6); 
  return "嗯，這個方法要用金針去刺入你的太陽穴，造成假死的現像，但需要一些工具，和藥物。
這些都準備齊了，再插入太陽穴即可，但目前我年老體衰，不適合遠遊，你可以去問問我大弟子劉進泉看看。";
}

string ask_tools()
{
  return "這個醫術需要需要冰雪寒絲針一隻。";
}

string ask_med()
{
  return "這個醫術需要祖傳的天靈丹一顆、魔戒的三葉仙蘭之葉一顆與蠍毒一份。";
}

void create()
{
  set("class", "doctor");
  set_name("華陀", ({ "master tor", "master", "tor" }) );
  set("title","銀針門第三代掌門人");
  set("nickname",HIC + "妙手回春" + NOR);
  set("gender", "男性");
  set("doctor/sosman", 1);
  set("max_gin",10000);
  set("max_sen",10000);
  set("max_kee",10000);
  set("age", 55);
  set("attitude", "heroism");
  set("long",
    "華陀為一代名醫,相傳曾為關公刮骨療傷過,可見其醫術的高明.\n"+
    "身為銀針門掌門的他，以發揚醫術為己任,對於患者絕對全力以赴..\n");
  set("str",18);
  set("cps",30);
  set("per",10);
  set("int",40);
  set("kar",16);
  set("bellicosity",1500);
  set("combat_exp",3000000);
  set("force",4000);
  set("max_force", 4000);
  set("force_factor", 10);
  set("score",200000);
  set("inquiry",([
    "百年榕樹根"   :  "嗯...此百年榕樹根，乃採自活餘百年之榕樹，據說凌雲村的
北方有顆高齡老樹，你不妨去看看！\n",
    "不傳之技"     :  (: ask_tor :),
    "難言之隱"     :  (: ask_savedie :),
    "看診"         :  (: ask_vet :),
    "李秋凡"       :  (: ask_lee:),
    "衝穴秘籍"     :  (: ask_secret:),
    "毒教"         :  "這種毒害大眾來增強自已實力的門派，實在是不足為取啊。\n",
    "衝穴"         :  "傳說中，可以突破被封住的穴道的一項技能，武林中很多人對此項技能非常眼紅。\n",
    "衝穴技巧"     :  "這都是傳說啦~~~~~~。\n",
    "靈魂出竅"     :  (: ask_soul:),
    "工具"         :  (: ask_tools:),
    "藥物"         :  (: ask_med:),
    "劉進泉"       :  "他是會靈魂出竅之技，不過因為他最近忙於手術之事，可能需要使一些計謀才有辦法讓他跟你走。",
    "計謀"         :  "這不是儒門拿手的，問我幹嘛？",
    "入閣令"       :  (: ask_pass:),
    "pass"         :  (: ask_pass:),
    "武林盟主"     : "年紀大，記不清楚了…你問問我的助手好了。",
  ]));
  set("functions/gold-needle/level",100);
  set("functions/break-kee/level",100);
  set_skill("godcure",100);
  set_skill("spells",20);
  set_skill("magic",20);
  set_skill("cure",120);
  set_skill("force",80);
  set_skill("move",60);
  set_skill("stabber",120);
  set_skill("parry", 50);
  set_skill("dodge",70);
  set_skill("poison",70);
  set_skill("literate", 80);
  set_skill("seven-steps",100);
  set_skill("yu-needle",100);
  set_skill("shinnoforce",80);
  map_skill("force", "shinnoforce");
  map_skill("dodge", "yu-steps");
  map_skill("stabber","yu-needle");
  map_skill("cure","godcure");
  map_skill("move","seven-steps");
  map_skill("parry", "yu-needle");
  set("chat_chance_combat",65);
  set("chat_msg_combat",({
    (: perform_action("yu-needle.gold-needle") :),
    (: perform_action("yu-needle.break-kee") :),
  }));

  create_family("銀針門", 3, "掌門人");
  setup();
  carry_object("/open/doctor/obj/cloth.c")->wear();
  carry_object("/open/doctor/obj/needle9.c")->wield();
  add_money("gold",10);
}

void init()
{
  object me=this_player();
  add_action("do_verify","verify");
  set_heart_beat(1);
  add_action("do_say","say");
  add_action("do_answer","answer");
  ::init();
}

int do_answer(string arg)
{
  object me = this_player();
  object ob = this_object();
  int i = (int)me->query_temp("torask");

  if(i) {
    if(!arg) return notify_fail("你要回答些什麼咧？\n");
    if((int)me->query_temp("wrong") >= 3)
    {
      message_vision("$n用力的敲了$N的頭一下！怒喝：你回去給我用功\幾年再來！\n",me, ob);
      return 0;
    }
    if(i == 1)
    {
      if(arg != "鐵牛運功\散")
      {
        command("say 錯！我銀針門怎麼會出了你這條蠢豬！");
        me->add_temp("wrong",1);
        return 1;
      }
      else
      {
        command("say 答對了！接下來問下一題！");
        me->add_temp("torask",1);
        command("say 請問狄鶯感冒了，鸚鵡要她喝什麼藥(answer)？");
        return 1;
      }
    }
    if(i == 2)
    {
      if(arg != "國安感冒糖漿")
      {
        command("say 錯！我銀針門怎麼會出了你這條蠢豬！");
        me->add_temp("wrong",1);
      }
      else
      {
        command("say 答對了！接下來問下一題！");
        me->add_temp("torask",1);
        command("say 請問什麼東西喝了甜甜的，效果快，恢復體力也快，真的好(answer)？");
        return 1;
      }
    }
    if(i == 3)
    {
      if(arg != "三支雨傘標友露安")
      {
        command("say 錯！我銀針門怎麼會出了你這條蠢豬！");
        me->add_temp("wrong",1);
      }
      else
      {
        command("spank "+me->query("id"));
        command("say 答對了！很好很好，你已經具有看診師的資格，可以替人看診(vet)了！");
        me->set("doctor/vet",1);
        me->delete_temp("torask");
        me->delete_temp("wrong");
        return 1;
      }
    }
  }
}

int do_say(string arg)
{
  object me=this_player();
  if( arg == "是" || arg =="願意")
  {
    if(me->query("doctor/book_select")==1)
    {
      if(present("book_mark",me))
        write("既然你已經持有了...那這面「入閣令」就不交給你了...\n" + NOR);
      else {
        write("既然你如此堅持...那這面「入閣令」就交給你了...\n" + NOR);
        message_vision("$N給$n一面" + HIY + "入閣令" + NOR + "。\n",this_object(),me);
        new("/open/doctor/obj/b-mark")->move(me);
      }
      command("addoil "+me->query("id"));
      me->delete("doctor/book_select");
      me->set("doctor/start_quest", 1);
      me->set("doctor/get_mark", 1);
      for(int i = i ; i<= 10; i ++) //因為藏經閣有根據doctor_book的quest 做更動 因此在此順便補上 by blazakira
      {
        tell_room(sprintf(resolve_path(__DIR__,"../room/book%1d.c"),i),HIG + "突然一道疾行的身影閃過眼前，害得你不小心推倒一旁的藏書，導致離開的路徑與先前不同囉。\n" + NOR);
      }
      load_object(resolve_path(__DIR__,"../room/book.c"))->random_road();
      return 1;
    }
  }
}

string ask_tor()
{
  object me;
  me=this_player();

  if(me->query("doctor/tell_woman")==1)
  {
    command("er "+me->query("id"));
    me->delete("doctor/tell_woman");
    me->set("doctor/ask_tor",1);
    return "";
  }
}

string ask_vet()
{
  object me = this_player();

  if(me->query("doctor/vet") == 1)
  {
    return "咦？你不是已經是個領有牌照了的看診師了嗎？";
  }
  if(!me->query_skill("cure") >= 120)
  {
    command("say 你的醫術這麼低，怎麼替人看診ㄚ？");
    return "再回去去多學幾年吧！";
  }
  if((int)me->query_temp("wrong") >= 3)
  {
    command("say 你怎麼還在這啊？");
    return "懷不快快給我滾回去！";
  }
  command("say 好！我要問你幾個問題，來確定你是否有資格擔任看診師的職位！");
  command("say 第一題！請問阿榮在軍中都吃他阿母寄去的什麼東西來強身(answer)？");
  me->add_temp("torask",1);
  return "";
}

string ask_savedie()
{
  object me;
  me=this_player();

  if(me->query("doctor/ask_tor")==1)
  {
    command("hmm "+me->query("id"));
    command("say 這...唉～好吧！我就把實情告訴你好了...");
    command("say 這不傳之技相傳是先祖神農氏在渡天劫之前傳授給後代的『聖手回春術』！");
    command("say 但是...此術早就失傳以久了，雖然好像有位本門前輩曾經習得此招...");
    command("say 不過傳言那位前輩多年前據說是在藏經閣修煉但之後便音訊全無...");
    command("say 而且距今也已經過了十多年了，我想...找著他的機率可說是微乎其微...");
    command("say 不過事關人命，不知道你是否願意去找找看呢？");
    me->delete("doctor/ask_tor");
    me->set("doctor/book_select",1);
    return "";
  }
}

int accept_object(object me, object ob)
{
  if(ob->query("id")=="ball of shen nongshi spirit")
  {
    write("你恭敬地將" + HIB + "神農氏靈魂珠" + NOR + "雙手呈上。\n" + NOR);
    command("say 這！這難道是！");
    command("applaud "+me->query("id"));
    command("say 沒想到你竟然能找回吾輩一生的宏願，真是太好了，終於可以見到古神神農氏了！");
    command("say 如果沒有他，我們這一門也沒辦法如此熟析藥草的使用。");
    command("say 去藏經閣吧，裡面有一本書，只有證明自己與神農氏有緣的人才能取得他畢生的著作。");
    command("say 取回神農氏靈魂珠的你證明有這緣份，進去拿吧!");
    me->set("quest/doctor_book/allow",1); //作為領取入閣令的許可 為永久mark 用以避免獎勵book遺失後 仍可進去重拿
    if(present("book_mark",me))
      write("既然你已經持有了...那這面「入閣令」就不交給你了...\n" + NOR);
    else {
      write("既然你如此堅持...那這面「入閣令」就交給你了...\n" + NOR);
      message_vision("$N給$n一面" + HIY + "入閣令" + NOR + "。\n",this_object(),me);
      new("/open/doctor/obj/b-mark")->move(me);
    }
    for(int i = i ; i<= 10; i ++)
    {
      tell_room(sprintf(resolve_path(__DIR__,"../room/book%1d.c"),i),HIG + "突然一道疾行的身影閃過眼前，害得你不小心推倒一旁的藏書，導致離開的路徑與先前不同囉。\n" + NOR);
    }
    load_object(resolve_path(__DIR__,"../room/book.c"))->random_road();
    return 1;
  }
  if(me->query_temp("sos_letter") && ob->query("id")=="oldman letter")
  {
    write("你戰戰兢兢的把信交給了華陀...\n" + NOR);
    command("mad");
    command("slap "+me->query("id"));
    command("say 你真是丟夠了吾的臉了！");
    command("say 人家被獨角虎咬傷了，你都不會醫，枉你算是我的得意弟子！");
    command("snort");
    command("say 算了！救人要緊，你現在先給我把獨角虎的角找來！");
    command("say ......還看啥看？快去ㄚ！！");
    me->set_temp("find_cornu",1);
    return 1;
  }
  if(me->query_temp("get_cornu")==1 && ob->query("id")=="cornu")
  {
    write("你把獨角虎的角交給了華陀...\n" + NOR);
    me->delete_temp("get_cornu");
    me->set_temp("find_root",1);
    destruct(ob);
    command("nod");
    command("say 不錯！是真品...那接下來給吾我去找百年榕樹根！");
    return 1;
  }
  if(me->query_temp("get_root")==1 && ob->query("id")=="root" && !me->query_temp("give_cornu"))
  {
    write("你把百年榕樹根交給了華陀...\n" + NOR);
    destruct(ob);
    command("spank"+me->query("id"));
    command("say 做得好...接下來給你將功\抵罪的機會...");
    write("華陀把兩樣藥材給製作成一顆藥丸，並交給了你...\n" + NOR);
    command("say 把這顆藥餵(feed)給那老人家吃就沒事了...");
    me->delete_temp("give_cornu");
    me->set_temp("get_pill",1);
    ob=new("/open/doctor/obj/tc-pill");
    ob->move(me);
    return 1;
  }
  if(me->query_temp("sec_letter") && ob->query("id")=="oldman letter2")
  {
    write("你把老頭的第二封信交給了華陀...\n" + NOR);
    command("haha "+me->query("id"));
    command("pat "+me->query("id"));
    command("say 你果然是我善良又老實的好弟子...");
    command("say 其實那個老頭是我的一位老友，我故意要他試探你的！");
    command("say 沒想到你的度量竟是如此寬大，將來肯定是個好醫生！");
    command("hoho");
    command("say 怎麼樣？沒嚇著你吧？");
    command("say 既然你如此的善良老實，吾想也應該把吾銀針門的奧義傳授給你了！");
    tell_object(users(),HIW + "
華陀笑道：" + HIY + "哇～哈哈哈！！\n
          " + HIG + ""+this_player()->name()+"" + HIY + "吾徒！\n
          吾今天就把咱" + HIW + "銀針門" + HIY + "的" + HIR + "七奇密式" + HIY + "傳授予你！！！！\n\n" + NOR);
    me->set("doctor/sosman",1);
    me->delete_temp("sec_letter");
    me->set("title",HBBLU+HIW + "ψ" + HIY + "七奇" + HIR + "秘針" + HIW + "ψ" + HIG + "傳人" + NOR);
    return 1;
  }
}

void attempt_apprentice(object ob)
{
  if(this_player()->query("class")!="doctor")
  {
    command("sigh");
    command("say 你不是醫者﹐我不能收你。\n");
    return;
  }
  if((int)ob->query_str() >19 )
  {
    command("sigh");
    command("say 你的膂力過大，拿起針來顫顫抖抖..\n敝人觀之"+ RANK_D->query_respect(ob) + "的資質似乎不宜！\n");
    return;
  }

  command("hmm");
  command("pat" + ob->query("id"));
  command("recruit "+ob->query("id"));
  message("system",HIR + "
" + HIW + "銀針門" + HIC + "內傳出一陣震耳的長嘯聲：\n
          " + HIR + "※" + HIW + "※ " + HIY + "楓~落~颯~颯~嘆~已~老" + HIW + " ※" + HIR + "※ \n
                     ※" + HIW + "※ " + HIY + "林~葉~飄~飄~塵~世~了" + HIW + " ※" + HIR + "※ \n
       " + HIW + "唉～吾今實老，但" + HIC + ""+this_player()->name()+"" + HIW + "既投入吾門之下，吾定好好栽培他！\n\n" + NOR,users());
}

void heart_beat()
{
  object me,boy;
  int value;
  me=this_object();
  if(me->query_condition("lyssa"))
  {
    me->clear_condition("lyssa");
    message_vision(HIY + "只見$N雙眼忽然湛放金光，大喝一聲，逼出了身上的狂犬病毒!!!\n",me);
  }
  boy=present("medicine boy",me);
  if(boy)
    if(boy->query_condition("lyssa"))
    {
      boy->clear_condition("lyssa");
      message_vision(HIG + "只見$N一掌拍在$n的背後，$n開始渾身冒汗，而$n身上的狂犬病毒似乎也跟著汗水排去!!\n",me,boy);
    }
  value=random(10);
  if( is_fighting() )
    if( value < 4){
      if( query("kee") < query("eff_kee") ) {
        message_vision(HIW + "\n華陀見情勢不妙,趕緊服下人靈丹,臉色頓時好多了\n" + NOR,me);
        me->receive_heal("kee",500);
        me->receive_heal("gin",200);
        me->receive_heal("sen",200);
        me->delete_busy();
        me->clear_condition();
        me->do_command("perform stabber.gold-needle");
      }
    }
    else if( value > 7)
      command("perform yu-needle.gold-needle");
    else if( value = 6)
      command("perform yu-needle.break-kee");
  ::heart_beat();
}

int do_verify(string arg)
{
  object me,ob;
  me=this_player();
  ob=new("/autoload/doctor/needle1");
  if( arg!="needle")
  {
    write("你要申請什麼\n");
    return 1;
  }
  if(me->query("family/family_name")!="銀針門")
  {
    write("只有銀針門徒才會有信物\n");
    return 1;
  }

  if( present("chhu needle",me) )
  {
    write("你已經申請過了\n");
    return 1;
  }
  else
  {
    write("華陀說：這是銀針門的信物 ,望你好好保存 ,切勿遺失了\n");
    ob->move(me);
    return 1;
  }
}

void unconcious()
{
  object winner = query_temp("last_damage_from");
  if(!winner){
    :: unconcious();
    return ;
  }
  tell_object(users(),HIW + "
銀針門" + HIR + "內突然傳出淒厲的慘叫聲...\n
          " + HIR + "門主" + HIW + "華陀" + HIY + "被"+HIG+winner->query("name")+HIR+"擊中要害，一時口噴鮮血，痛苦不已...\n
                  " + HIR + "霎時一道紅光閃過" + HIW + "楓林港" + HIR + "的天空...難道竟是天命註定如此...？\n
\n" + NOR);
  :: unconcious();
}

void die()
{
  object winner = query_temp("last_damage_from");
  int j;
  if(!winner)
  {
    ::die();
    return ;
  }
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj2/charity_stone")->move(environment(winner));
        message_vision(HIM + "\n從華陀的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj2/charity_stone",sprintf("%s(%s) 讓華陀掉下了仁心石於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
      {
        new("/open/sky/obj2/charity_stone")->move(environment(winner));
        message_vision(HIM + "\n從華陀的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj2/charity_stone",sprintf("%s(%s) 讓華陀掉下了仁心石於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  tell_object(users(),HIW + "
銀針門" + HIR + "內傳出一聲怨恨的嘆息聲～～～\n
     " + HIW + "「想我" + HIG + "華陀" + HIW + "行醫數十年，救人無數，如今竟命喪-"+HIR+winner->query("name")+HIW+"-之手...」 \n
             " + HIW + "一顆" + HIY + "*流星*" + NOR + "劃過" + HIC + "銀針門" + HIW + "的上空～～～ \n
                         " + HIR + "一代神醫" + HIG + "「華陀」" + HIW + "就此殞落....\n\n" + NOR);
  ::die();
}

string ask_secret()
{
  object me = this_player();
  if(!me->query_temp("quests/acup"))
  {
    return "嗯....我想這件事你還是不要知道的好。";
  }
  me->set_temp("quests/acup",2);
  return  "沒想到你知道了，這本書可以讓人學會衝穴技巧，而這項技能可以讓人在戰鬥中，衝破\n"+
    "被封鎖的穴道，但因為武學限制的關係，只有段家、醫生與毒教有辦法使用。\n"+
    "但這一本書，有一次被魔教奪走了，我派出去的徒兒李秋凡就這樣一去不回。\n";
}

string ask_lee()
{
  object me = this_player();
  if(!me->query_temp("quests/acup"))
  {
    return "嗯....我想這件事你還是不要知道的好。";
  }
  if(me->query_temp("quests/acup") == 12)
  {
    me->set_temp("quests/acup", 13);
    return "你問秋凡徒兒嘛？他正在東廂房休息，我想他應該也很想見到你吧。";
  }
  if(me->query_temp("quests/acup") == 2)
    me->set_temp("quests/acup", 3);
  command("sigh");
  return "多年前，我聯合段家並派他去跟被魔教教主敬柔奪取的衝穴秘籍，可是他竟然\n"+
         "一去不回，我派了多人去尋找，但還是找不到，猜想應該在半途中遭到不測了。\n";
}

void greeting(object obj)
{
  if(obj->query_temp("quests/acup") == 11)
  {
    foreach(object mob in all_inventory(environment()))
    {
      if(mob->query_leader() == obj)
      {
        if(mob->query("no_attack") && mob->query("no_hurt"))
        {
          mob->call_find_master(obj,this_object());
        }
      }
    }
  }
  if(!present("ball of Shen Nongshi spirit",obj) && !obj->query("quests/doctor_book")) { //如果已經拿到靈魂珠或且解謎成功就跳過
    if( !obj->query_temp("quests/doctor_book/check") && obj->query("family/family_name")=="銀針門" ) {
      if( present("spica soul splinters",obj) || present("kui soul splinters",obj) ||
          present("jing soul splinters",obj) || present("star soul splinters",obj) ||
          present("lin soul splinters",obj) ) { //如果遇到的玩家持有關鍵道具 且並非第一次遇到
        obj->set_temp("quests/doctor_book/check",1);
        tell_object(obj,"\n"+HIY+
          "華陀說道：你從哪邊找到這個神農靈魂碎片的？你知不知道我找此神農靈魂碎片已經很久了，\n"+
          "          我本以為在我有生之年內無法完成此願望，沒想到竟然讓你找到了。可惜這不是完\n"+
          "          整的靈魂碎片，此靈魂碎片共有五塊，分別為角、奎、井、星、麟，蒐集完畢後，\n"+
          "          去找老不死吧！他能把殘缺靈魂組合起來。\n\n"+NOR);
        call_out("do_take",2,obj);
      }
    }
    else if( !obj->query_temp("quests/doctor_book/check") && obj->query("family/family_name")!="銀針門" ) { //其他門派時
      if( present("spica soul splinters",obj) || present("kui soul splinters",obj) ||
          present("jing soul splinters",obj) || present("star soul splinters",obj) ||
          present("lin soul splinters",obj) ) {
        obj->set_temp("quests/doctor_book/check",1);
        tell_object(obj,"\n"+HIY+
          "華陀說道：你從哪邊找到這個神農靈魂碎片的？你知不知道我找此神農靈魂碎片已經很久了，\n"+
          "          我本以為在我有生之年內無法完成此願望，沒想到竟然讓你找到了。可惜這不是完\n"+
          "          整的靈魂碎片，此靈魂碎片共有五塊，分別為角、奎、井、星、麟，我個人希望你\n"+
          "          能交給本門保管，因為這與本門淵源頗深，本門正傾全力找尋中。\n\n"+NOR);
        call_out("do_take",2,obj);
      }
    }
  }
}

string ask_pass()
{
  object me = this_player();
  if(!me->query("doctor/get_mark") && !me->query("quest/doctor_book/allow"))
  {
    return "嗯....我想這件事你還是不要知道的好。";
  }
  if(present("book_mark",me))
  {
    return "疑？你不是已經持有了？";
  }
  new("/open/doctor/obj/b-mark")->move(me);
  message_vision(HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "$N說道: 咦？$n想進去看書？好徒兒，有上進心是很不錯的。\n" + NOR + "$N給$n一面" + HIY + "入閣令" + NOR + "。\n",this_object(),me);
  return "";
}

int do_take(object me) //保管人是義女華山蝶
{
  object ob = this_object();
  if ( !me || environment(me) != environment(ob) ) return;
  tell_object(me,HIY + "頓了頓華陀接著說道：你可以先將這片靈魂碎片交由(give)我的義女保管。\n\n"+NOR+
    "相關說明 help doctor.失落的靈魂碎片\n\n");
}
