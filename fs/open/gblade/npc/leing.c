inherit NPC;

string do_ask (object me);
string ask_dancer();
string ask_finalwar();
string ask_moon();
string ask_ring();
string ask_white();
void create()
{
        set_name("王鐘靈", ({ "leing",}) );
        set("long", "
她是王家的大小姐，只見兩灣似蹙非蹙的籠煙眉，一雙似喜非喜的含情
目，嬌喘微微；瞧這樣子似乎是體弱多病的富家千金，怎麼也不像武林
世家的子弟。\n");
        set("title","金刀王家千金大小姐");
        set("nickname","八面玲瓏");  
        set("age", 21);
        set("int", 30);
        set("cps", 25);
        set("str", 22);
        set("cor", 23);
        set("spi", 30);
        set("con", 24);
        set("kar", 28);
        set("per", 30);
        set( "force_factor", 6 );
	set("combat_exp",100000);
        set("force",600);
        set("max_force",600);
        set_skill("blade", 50);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set_skill("force", 50);
        set_skill("literate",90);
	set_skill("gold-blade",60);
	set_skill("unarmed",40);
        set_skill("sixforce",40);
        set_skill("fly-steps",90);
        set_skill("move",60);
        map_skill("force", "sixforce");
        map_skill("blade", "gold-blade");
        map_skill("dodge", "fly-steps");

        set( "gender", "女性");

        set("limbs", ({ "頭部",  "雙腳", "雙手", "背部" ,"腹部","腰部"}) );
     
        set("attitude", "peaceful");

        set("chat_chance", 2);
        set("chat_msg", ({
         "王鍾靈不斷的嘆氣，似乎有什麼心事。\n",
         "王鍾靈嘆道：『相思有如少債的。每日相催逼。常挑著一擔愁，准不了三
分利。這本錢見他時才算得。』正是徐再思的清江引--相思。\n",
         "王鍾靈道：『伴夜月銀箏鳳閑。暖東風繡被鴛慳。信～沈了魚，書～絕了
雁。盼雕鞍萬水千山。本利對相思若不還。只告與那能索債愁眉淚\眼....\n"
        }) );
         set("inquiry",([
        "王元霸" : "就是我爹啊 !\n",
	"神兵利器" : "據我所知 , 當今的神兵利器 , 首推玉衡天劍和龍虎刀 !\n",
	"玉衡天劍" : "那是仙劍派開山祖師逍遙子的佩劍 !\n",
	"龍虎刀"   : "龍虎刀是我金刀門至寶 , 先祖王蹇之佩刀 !\n",
        "心事" : "嗯 , 你會將心事告訴漠生人嗎 ?\n",
	"古文書" : "這個我略懂一些，大概看得懂兩三成吧！\n",
        "古文" : "這個我略懂一些，大概看得懂兩三成吧！\n",
        "翻譯" : "你要我幫你翻譯古文？那要把要我翻譯的東西交給我呀！\n",
        "白孝虹" : "你問這個要做什麼呢？\n",
        "巧兒" : "她實在是一個聰慧的女孩子。\n",
        "無忌" : "嗯....是誰阿？沒聽過....等等我想起來了，聽說我妹很喜歡他。\n",
        "神槍" : "那是由神之國『努曼諾爾』帝國所鑄，精靈王擁有的霸王之槍「伊洛斯」\n",
        "聖劍" : "那是由神之國『努曼諾爾』帝國所鑄，人皇所持有的皇者之劍「納希爾」\n",
	"月半彎"  :  (: ask_dancer :),
        "最終戰役"  :  (: ask_finalwar :),
        "魔戒"  :  (: ask_ring :),
        "太陰一派"  :  (: ask_moon :),
        "白袍聖徒"  :  (: ask_white :),
        ]));
      
        setup();

	carry_object("/open/gblade/obj/mandarin_duck-blade.c")->wield();
	carry_object("/open/gblade/obj/topknot.c")->wear();
	carry_object("/open/gblade/obj/glow-cloth")->wear();
	carry_object("/open/gblade/obj/boots1.c")->wear();
        add_money("gold",5);
}

int accept_object(object who,object ob)
{
        string ob_id;
        ob_id=ob->query("id");
        if(ob_id=="papyrus")
        {
	if(who->query("quests/lotch") || who->query("lotch")>0)
	{
	command("say 我不是幫你翻譯好了 ?");
	return 1;
	}
        command("say 你稍微等一下。");
	message_vision("王鐘靈拿出了紙筆 , 開始翻譯 !\n",this_player());
	call_out("do_give",10,this_player());
	}
        if(ob_id=="oldnote")
        {
        command("say 請稍微等一下。");
	message_vision("王鐘靈拿出了一本古老的字典 , 開始著手翻譯 !\n",this_player());
	call_out("do_translate",10,this_player());
        }
  return 1;
 }
string ask_dancer()
{
    if(!this_player()->query_temp("ask_moon5"))
	return "嗯....這我可不清楚﹐你最好問問別人吧。";
	this_player()->set_temp("ask_moon6",1);
	command("say 自從她情海生變後,只託人給了我一封信說她想遠離塵世,到深山隱居。");
	command("say 我也曾利用出遊之際遍訪群山,可惜始終未能找到她的蹤跡。");
	return "希望你能順利找到她,我也希望能再與她相聚......";	
}    
void do_give(object who)
{
        command("say 這本書你是從那裡找來的，上頭寫的都是我們金刀門的歷史。");
        command("say 這是譯文，有些是我讀不懂，有些因為書殘缺，所以譯不全。");       
        new("/open/gblade/obj/paper.c")->move(who);
	message_vision("王鐘靈將譯好的紙張 , 交給了$N\n",who);
	who->set("lotch",1);
}

void do_translate(object who)
{
     if(who->query_temp("find_moon") == 8)
      {
        command("say 想不到我居然有幸能見到這遺卷，這可是史前的偉大聖徒所留下的警示。");
        command("say 裡面交代了魔大戰的「最終戰役」結果，以及遠古魔法的去向。");       
	who->set_temp("find_moon",9);
      }else command("say 這上面說：早睡早起身體好，解迷最好別亂跳。");  
}

string ask_finalwar()
{
     object me = this_player();
     if(me->query_temp("find_moon") >= 9)
      {
      	if(me->query_temp("find_moon") == 9)   me->set_temp("find_moon",10);
        return "
        在這場大戰中，人皇及精靈王雙雙隕落，而他們的武器「神槍」及「聖劍」亦當場斷折。
        但人族皇太子拾起斷折的聖劍，及時斬落暗之王者手中的「魔戒」，因而獲得最後勝利。";     
      } 
}

string ask_ring()
{
     object me = this_player();
     if(me->query_temp("find_moon") >= 10)
      {
      	if(me->query_temp("find_moon") == 10)   me->set_temp("find_moon",11);
        return "
        這枚魔戒，在魔法紀元結束之後，輾轉幾番易主，落入了「太陰一派」的手中。
        所以在我們這個凡人的時代，再度見證到遠古魔法的出現。";       
      }
}

string ask_moon()
{
     object me = this_player();
     if(me->query_temp("find_moon") >= 11)
      {
      	if(me->query_temp("find_moon") == 11)   me->set_temp("find_moon",12);
        return "
        太陰一派憑著魔戒的力量研究出凌厲無比的『太陰虛幻神鑑』，但卻受到魔戒操控，開始肆虐人間。
        於是「白袍聖徒」帶著重鑄的聖劍及神槍再度出現，引導當時的正道圍攻太陰一派。";  
      }
}

string ask_white()
{
     object me = this_player();
     if(me->query_temp("find_moon") >= 12)
      {
      	if(me->query_temp("find_moon") == 12)   me->set_temp("find_moon",13);
        return "
        在聖徒帶領下，終於將太陰一族消滅，魔戒在神槍和聖劍的打擊下灰飛湮滅。
        然而太陰一族的餘黨卻帶著神槍和聖劍的碎片逃跑消失，太陰虛幻神鑑亦不知所蹤。";
      }
}
