#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
inherit SSERVER;
string ask_test()
{
 if(this_player()->query("quests/yan")==3)
 {
if(this_player()->query("quests/fear_fighting",1) && this_player()->query("quests/yantestmark2",1) )
  {

  command("say 謝謝您的幫忙.我願意將appo給我的印記傳到你身上!\n");
  tell_object(this_player(),HIW + "瞬間由聖賢書將手搭在你的肩上..你頓時覺得
一股暖意由聖賢書的手中傳過來\n" + NOR);
  this_player()->delete("quests/2ndtest",i);
  this_player()->set("quests/yantestmark3",1);
  return("這是最後一個了...你趕快去完成你的測驗吧~\n");
  }
 else if (this_player()->query("quests/yantestmark3")>1)
  return ("我已經把印記給你了..你還要做什麼\n");
 else
  return ("解決我的問題..我就跟你說印記在哪\n");
 }
else
 return ("啥印記..你在說什麼?\n");
}

string so()

{
        if( this_player()->query("quests/kill-snow") ) return " ??";
        this_player()->set_temp("ask_so",1);
        return "因此我想請人代我前去﹐不知閣下是否肯幫在下這個忙﹐聖某當有重酬﹗\n";
}

string liyu()
{
object me,ob;
me = this_player();
if (me->query("liyu") != 4)
{
command("say 你說開天三靈器之一呀....原本他是在儒門中沒錯....不過....在先前綠毛老祖率眾入侵時....不小心遺失了.....記得當時好像是被七位不知名的人士給偷走.....如果你想知道是誰拿走的.....你去找諸葛神算他可以幫你算算看....");
me->set("liyu",1);
}
else
{
command("say 我才剛剛拿回麗玉蝶蘭...你就..唉算了.物贈有緣人..你去拿吧.. 就在此處的enter");
me->set("liyu",5);
}
}
string book()
{
        object ob, me= this_player();
// Add By AceLan....不是儒門的不準拿書....ccc....
    if( me->query_temp("get_war_book"))
    return "書只有一本, 不是已經給你了嗎...\n";
    if( present( "war book" , me ) ) 
    return "你不是有了嗎 ?\n";
        ob = new("/daemon/class/scholar/book");
        ob->move( me);
        message_vision("$N給$n一本"+ob->name()+"\n",this_object(),
    me);
    me->set_temp("get_war_book", 1);
        return "這本兵法﹐你好好地看吧。\n";
}

int finish( object me )
{
        object obj ;
        command("say 十分感謝閣下的相助﹐這有一支青龍之笛﹐乃聖某家傳之寶。");
        message_vision("$N給$n一支笛子。\n",this_object(),me);
        obj = new("/open/snow/obj/de");
        obj->move( me );
        me->set("quests/fear_fighting",1);
}
string ask_picture()
{
        if( present( "snow picture" , this_player() ) )
                return "由於諸葛臥龍的八陣圖非常的玄妙﹐所以你如果沒仔細看清楚路觀圖是沒辦法找到路口的。\n";
        return "你問我 ? 我問誰啊 ?\n";
}
string ask_place()
{
        object ob;
        command("say 諸葛臥龍就隱居在雪蒼山腳﹐但是一般人是無法輕易找到他的。");
        command("say 因為他在外面佈下了「八陣圖」﹐若無特殊方法是找不到的。\n");
        command("say 這有一張路觀圖﹐你拿去吧。");
        ob = new( "/open/snow/obj/picture" );
        ob->move( this_player() );
        message_vision("$N給$n一張路觀圖。\n",this_object(),this_player());
        return "祝你好運 ... ";
}
string ask_ball()
{
 if(!this_player()->query_temp("swordtime"))
 {
  return ("對不起﹐你問的事我實在沒有印象。");
  }
 else
  {
  if (this_player()->query("class")=="scholar"&&this_player()->query_temp("swordquest/findball")==3)
    {
    this_player()->set_temp("swordquest/findball",4);
    return ("在金風細雨樓樓主林靜詩尚在武林之際﹐在下曾有幸目睹該寶珠﹐但在其隱遁後﹐似乎曾在京城看過它的鋒芒。\n");
   }
else return ("對不起﹐你問的事我實在沒有印象。");
 }
}
void create()
{
        set_name("聖賢書",({"master sue","sue"}));
        set("long","他是一個十分儒雅的年輕人﹐但卻是武林中的有名的俠客。\n");
        set("gender","男性");
        set("class","scholar");
        set("nickname","九指書生");
        set("combat_exp",3000000);
        set("attitude","heroism");
        set("age",26);
        set("str", 44);
        set("cor", 45);
        set("cps", 18);
        set("per", 24);
        set("int", 42);
        set("max_gin",10000);
        set("s_kee",1000);
        set("max_s_kee",1000);
        set("sec_kee","god");
        set("force",5000);
        set("max_force",5000);
        set("max_kee",10000);
        set("kee",10000);
        set("max_sen",10000);
        set("sen",10000);
        set_skill("literate",120);
        set_skill("cure",60);
        set("force_factor",10);
        set_skill("force",80);
        set_skill("stabber",120);
        set_skill("dodge",70);
        set_skill("knowpen",100);
        map_skill("stabber","knowpen");
        set_skill("parry",70);
        set_skill("poetforce",80);
        map_skill("force","poetforce");
        map_skill("parry","knowpen");
        set_skill("unarmed",20);
        set_skill("move",70);
        set_skill("plan",120);
        set_skill("winter-steps",100);
        map_skill("dodge","winter-steps");
        set_skill("god-plan",100);
        map_skill("plan","god-plan");
        set("functions/movedown/level",100);
        set("functions/finger/level",100);
        set("plan-quest/ko-fire-king",1);
        set("chat_chance_combat", 100);
        set("inquiry",([
        "挑戰書" : "最近莫名奇妙地接到了一張挑戰書﹐真是令人困擾。\n",
        "困擾" : "我早就不問紅塵世事了﹐但是不去赴約﹐又恐為天下人所恥笑﹐因此...\n",
        "血魔" : "ㄚ~~~你問這個.....該不會血魔已經破封了.....唉..蒼生不幸....",
        "儒俠" : "這是當年夫子的不傳弟子..不過已經消失一陣子了\n",
    "麗玉蝶蘭" : (: liyu :),
        "血魔封印" : "當初為了將血魔封印...仙劍逍遙子將其配劍[仙劍連陽]請劍師龍鐵心鑄成開天三靈器...一傳刀神..一傳儒俠..一傳其傳人.並利用三靈器的聖氣壓制血魔魔氣",
        "逍遙子" : "仙劍祖師爺ㄚ~~~仙魔戰後已不知去向....",
        "龍鐵心" : "先師說是天下間最有才華的鑄劍師了...由於個性古怪..所以一般材料他都看不上眼....真不曉得[仙劍連陽]是怎麼做成的...",
        "因此" : (: so :),
        "青龍之笛" : "此乃家傳之寶﹐據家父說使用此笛(use)可以召喚出傳說中的青龍﹐但是必須在特定之處使用﹐至於要在那裡使用﹐我就不得而知。",
        "去老還童術" : "我有聽說過武林中有一個寶物「鎖元盒」﹐用這個寶物再加上青龍之氣就能產生返老還童的效果﹐但是方法如果我並不清楚。\n",
        "鎖元盒" : "這樣寶物似乎早在二十年前左右就已經失落。\n",
        "邢賢書" : "嗯 ... 不瞞閣下﹐在下本姓邢﹐後改姓聖﹐「邢賢書」乃是在下早名也。\n",
        "神算先生" : "此人複姓諸葛名臥龍﹐乃當今知識之奇葩﹐無論是兵法、文學、政治、卜卦、醫術﹐他樣樣精通。\n",
        "諸葛臥龍" : "此人雖有蓋\世之才﹐然不得時也﹐如今此人隱居於雪蒼山下。\n",
        "六韜奇略" : "六韜奇略是兵法家黃石公收集戰國奇略所寫之書, 不過他行事乖僻, 很難找到他。\n",
        "雪蒼山下" : (: ask_place :),
        "路觀圖" : (: ask_picture :),
        "試煉印記" : (: ask_test :),
        "孔明兵法" : (: book :),
        "麗玉蝶蘭晶珠" : (:ask_ball:),
        ]));
        set("chat_msg_combat",({
        (: perform_action,"stabber.movedown" :),
        (: perform_action,"stabber.finger" :),
        (: perform_action,"plan.lock-link" :)
        }));
        setup();
        create_family("儒門",16,"弟子");
        carry_object(START_OBJ"ten_pen")->wield();
        carry_object(START_OBJ"k_cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if(this_player()->query("class")!="scholar")
        {
                command("say 汝非儒生也﹐焉能收汝為徒乎 ?\n");
                return;
        }
        command(":)");
        command("recruit "+ob->query("id"));
}
void init()
{
        object me = this_player();
        if( me->query("quests/kill-snow") && !me->query("quests/fear_fighting") )
                call_out("finish",1,me);
        add_action("do_nod","nod");
}
int do_nod()
{
        object ob = this_object() , me = this_player();
        object obj;
        if( me->query("quests/kill-snow") ) return 0;
        if( !me->query_temp("ask_so") ) return 0;
        if( me->query_temp("get_letter") ) return 0;
        command("say 那麼 .... 就煩勞你了。");
        obj = new("/daemon/class/scholar/letter");
        obj->move( me );
        message_vision("$N給了$n一張書信。\n",ob,me);
        me->set_temp("get_letter",1);
        return 1;
}
int accept_fight(object who)
{
 command("cmd god_kee");
 fight_ob(who);
 command("perform plan.fire");
 return 1;
}

int accept_kill(object who)
{
  command("say 讓你嘗嘗身處烈火之中的滋味！\n");
 kill_ob(who);
 command("cmd god_kee");
 command("perform stabber.movedown");
 return 1;
}
int accept_object(object me, object obj)
{
        if( obj->query("name") == "孫子兵法" )
        {
          command("pat "+getuid(me));
          command("say 有何處不懂呢???讓為師來指導你吧。");
          if( me->query("family/family_name") == "儒門" && !me->query("marks/kid-book") )
          {
            command("say 想不到你如此專心，就傳授你諸葛神算吧．");

write(this_object()->query("name")+"指導著你心中的疑惑。\n\n"+
            "你覺得心中疑惑豁然貫通, 對兵法的認知更上一層。\n\n"+
            "你的諸葛神算達到上限了。\n\n"+
            "你已經完全了解了兵法的知識了。\n\n");
            if( me->query("force") < me->query("max_force") )
              me->set("force",me->query("max_force"));
            me->set("marks/kid-book",1);
          }
          destruct(obj);
        }
        else
          command("? "+getuid(me));
        return 1;
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
        if(winner->query("family/family_name")=="仙劍派" && winner->query("killyao")==1 && winner->query("bloodsword")==1)
        {
        object me,ob;
        me = this_player();
        ob=new("/open/gsword/obj1/brain.c");
        tell_object(winner,HIR + "你從屍體上挖出了一顆血淋淋的大腦.." + NOR);
        ob->move(winner);
        winner->set_temp("swordbrain",1);
        }

/*        if ( winner->query_temp("bless")==1 )
        {
        j=random(-1);
          if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
          {      
          new("/open/sky/obj3/water_feather")->move(environment(winner));
          message_vision(HIM + "\n從聖賢書的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/water_feather",sprintf("%s(%s) 讓聖賢書掉下了水之流羽於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }else{
        j=random(-1);
          if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
          {      
          new("/open/sky/obj3/water_feather")->move(environment(winner));
          message_vision(HIM + "\n從聖賢書的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/water_feather",sprintf("%s(%s) 讓聖賢書掉下了水之流羽於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }
*/
        tell_object(users(),HIW + "\n
儒門" + HIR + "傳來了如洪鐘般的嘆息...\n
             " + HIG + "『 經 綸 百 世 路 綿 延 ， 
                    觸 念 塵 緣 不 計 年 ； 
                        慈 心 解 去 風 雨 衣 ，
                            明 燈 長 照 九 重 天 。 』\n" + HIY + "
                    「" + HIW + "風雅書" + HIY + "..." + HIW + "廣文書" + HIY + "...汝等要替我報仇也...」\n" + HIR + "
            儒門九代令公之首「" + HIY + "聖賢書" + HIR + "」如今竟不幸命葬於" + HIG+winner->name()+HIR + "之手....\n\n" + NOR);

        ::die();
}






