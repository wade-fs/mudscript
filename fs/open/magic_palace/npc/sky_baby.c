#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 
inherit NPC;
inherit SSERVER;
string do_ask1();
string do_ask2();
string do_ask3();
string do_ask4();
string do_ask5();
string do_ask6();
string do_ask7();
string do_ask8();
string do_ask9();
object me;
object book;
void create()
{
        set_name("天嬰",({"Sky Baby","baby"}));
        set("long","
英雄新經傳人，表面上修習玄門正派的武功，事實上暗藏禍心...
\n" + NOR);
        set("attitude", "friendly");
        set("gender","男性");
        set("combat_exp",5000000);
        set("score",300000);
        set("sec_kee","god");
        set("max_s_kee",100);
        set("s_kee",1000);
        set("age",25);
        set("class","dancer");
        set("family/family_name","夜夢小築");
        set("title",HIC + "『英雄新經』" + HIW + "傳人" + NOR);
        set("nickname",HIR + "英雄正宗" + NOR);
        set("chat_chance", 10);
        set("max_gin",20000);
        set("max_kee",50000);
        set("max_sen",20000);
         set("bellicosity",10000);
        set("max_force",10000);
        set("force",40000);
        set("max_atman",10000);
        set("max_mana",10000);
        set("atman",10000);
        set("mana",10000);
        set("force_factor",35);
        set("str",35);
        set("cor",20);
        set("cps",20);
        set("int",20);
        set("con",20);
        set("per",20);
        set("spi",20);
        set("kar",10);
        set_skill("hero",99);
        set_skill("badforce",150);
        set_skill("dreamdance",100);
        set_skill("unarmed",120);
        set_skill("literate",100);
        set_skill("ghost-steps",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("force",350);
        map_skill("unarmed","hero");
        map_skill("parry","dreamdance");
        map_skill("force", "badforce");
        map_skill("dodge", "ghost-steps");
        set("inquiry", ([
            "魔界金典"  :       (: do_ask1 :),
            "英雄真經"  :       (: do_ask2 :),
            "英雄新經"  :       (: do_ask3 :),
            "劍光芒"    :       "他目前位居天下四絕之一，我所學的英雄新經就是他傳授的。",
            "武聖"      :       "就是武聖盟盟主--劍光芒。",
            "柳葉山莊"  :       (: do_ask4 :),
            "閃電山莊"  :       (: do_ask5 :),
            "天劍宗"    :       (: do_ask6 :),
            "無雙寺"    :       (: do_ask7 :),
            "少林寺"    :       (: do_ask8 :),
            "四絕"      :       "天底下除了魔界金典和英雄真經之外最強的四個人，分別是虎神、九魔龍、武聖、和萬世教主。現在應該都聚集在魔宮了。",
            "天下四絕"  :       "天底下除了魔界金典和英雄真經之外最強的四個人，分別是虎神、九魔龍、武聖、和萬世教主。現在應該都聚集在魔宮了。",
            "虎神"      :       "他就是當今權傾天下的朝廷大將軍--孫虎臣，其天虎橡皮勁為天下第一防禦武技。",
            "九魔龍"    :       "漢江水中寨寨主--完顏烈火，其破綻之拳和霸王金身已達攻擊和防禦的顛峰之境，但傳說他另有一套神秘的不世魔功...",
            "萬世教主"  :       "原為北方高麗人，其所創的萬世教為天底下最神秘的組織，他本人的武功則以強橫霸道敏捷兼而有之的雷電冰火為主。",
            "魔宮"      :       "傳說為魔界金典誕生的地方，位於人魔交界之處，據聞林宏昇知道一點風聲...",
        ]) );
        setup();
        carry_object("/open/capital/obj/icer")->wield();
        add_money("diamond", 1);
}

void init()
{
       add_action("do_nod","nod");
       ::init();
}

int do_nod(string arg)
{  
   me = this_player();
   if(arg == "baby" && me->query_temp("kill_hero") == 2)
   {
    command("sigh");
    message_vision(HIY + "天嬰說道:「想不到魔界金典和英雄真經最後竟被其他武功所打敗。」\n" + NOR,me);
   }else{
   command("stare " + me->query("id"));
        }
   return 1;
}

string do_ask1()
{
   me = this_player();
     if(me->query_temp("kill_hero") == 2 && !me->query_temp("get_new"))
   {
   me->set_temp("ask_magic",1);
   return "「那是魔也佛的武功，三百年前的無敵傳說，當時只有修習英雄真經的英雄和尚能與他匹敵。」\n";
   }else{
   return "「無名小卒不配知道魔界金典的事，滾!!」\n";
        }
}

string do_ask2()
{
   me = this_player();
   if(me->query_temp("ask_magic"))
   {
   me->set_temp("ask_hero",1);
   return "「英雄真經由三百年前五大玄門正派匯聚各種絕學而成，威力強大，與魔界金典齊名。
            不過絕對比不上『武聖』劍光芒所授與我的武技。」\n";
   }else{
   return "「連魔界金典都不知道，還談什麼英雄真經!!」\n";
        }
}

string do_ask3()
{
   me = this_player();
   if(me->query_temp("ask_hero"))
   {
   me->set_temp("ask_new_hero",1);
   return "「英雄新經是在十年前，由三百年前五大玄門正派後裔所重新研發的武學，
            包含了柳葉山莊、天劍宗、無雙寺、少林寺、以及閃電山莊的高深武技，
            試想三百年來武學必定經過許\多改良，所以英雄新經絕對勝過英雄真經!!」\n";
   }else{
   return "「連魔界金典和英雄真經都不知道，還談什麼英雄新經!!」\n";
        }
}

string do_ask4()
{
   me = this_player();
   if(me->query_temp("kill_hero"))
   {
   me->set_temp("ask_blade",1);
   command("sigh");
   return "「柳葉山莊的武學是霸道至極的刀法，然而我發現英雄新經上所載的刀法
            並非柳葉山莊最極致的招式，因此很想去強取精髓，無奈年前柳葉山莊
            和金刀門結盟之後，勢力如日中天，難以撼動其根基。」\n";
   }else{
       return "「無名小卒不配知道柳葉山莊的事，滾!!」\n";
        }
}

string do_ask5()
{
   me = this_player();
   if(me->query_temp("kill_hero"))
   {
   me->set_temp("ask_steps",1);	
   command("hmm");
   return "「閃電山莊武學正如其名，為迅捷如電的閃電身法，然其記載於英雄新經
            上的只是最進階最粗淺的閃電步，聽說最近有個身手佼捷的小偷將密笈
            給偷了出來，真希望我也能學到...」\n";
   }else{
       return "「無名小卒不配知道閃電山莊的事，滾!!」\n";
        }
}

string do_ask6()
{
   me = this_player();
   if(me->query_temp("kill_hero"))
   {
   me->set_temp("ask_sword",1);
   command("snort");
   return "「天劍宗的劍技為虛空馭劍之術，講求以氣馭劍，傷人於百步之外，但
            宗主漢通神受到鄭士欣那老頭的蠱惑，竟將精奧之處私藏，待我設法
            練成其最高境界後，定要一舉殲滅天劍宗及仙劍派，以吐怨氣。」\n";

   }else{
       return "「無名小卒不配知道天劍宗的事，滾!!」\n";
        }
}

string do_ask7()
{
   me = this_player();
   if(me->query_temp("kill_hero"))
   {
   me->set_temp("ask_fist",1);	
   command("kick");
   return "「無雙寺的絕技為無雙拳，拳勁如雷驚天，如山沉重，雖我已練成其
            最高境界，但總覺得行招之間有所滯澀，上次去那邊找無垢老和尚
            興師問罪時，竟碰巧遇到聖火教皇找他討論拳招，因此大敗而歸。」\n";
   }else{
       return "「無名小卒不配知道無雙寺的事，滾!!」\n";
        }
}

string do_ask8()
{
   me = this_player();
   if(me->query_temp("kill_hero"))
   {
   me->set_temp("ask_force",1);
   command("sigh");
   return "「少林寺向來為中原正道武學重鎮，其內功更是冠絕武林，我本是少林
            弟子，因此身負高深莫測的『菩提拂拭神功』，但日前與慈恩老禿驢
            切磋時，竟發現他練有更精深的心法，無奈少林高人輩出，難以下手。」\n";
   }else{
       return "「無名小卒不配知道少林寺的事，滾!!」\n";
        }
}

void greeting(object me)
{
object ob1,ob2,ob3,ob4,ob5;
me = this_player();
ob1 = present("Leaf_Book",me);
ob2 = present("Fist_Book",me);
ob3 = present("Force_Book",me);
ob4 = present("Thunder_steps Book",me);
ob5 = present("Control_sword book",me);
  if(!me->query_temp("get_new"))
if(present("Leaf_Book",me) && present("Fist_Book",me) && present("Force_Book",me) && present("Thunder_steps Book",me) && present("Control_sword book",me) && me->query_temp("kill_hero") == 2 )
{
command("spank " + me->query("id"));
message_vision(HIY + "天嬰說道:「" + me->query("name") + "真的全拿到了!?哈哈哈哈，所謂踏破鐵鞋尋覓處，得來全不費功夫，
           失去利用價值的人，已不需要活著了，死吧!!」\n" + NOR,me);
kill_ob(me);
me->set_temp("can_kill_baby",1);
destruct(ob1);
destruct(ob2);
destruct(ob3);
destruct(ob4);
destruct(ob5);
}else{
if(me->query_temp("kill_hero") == 2)
{
command("wa");
message_vision(HIY + "天嬰說道:「"+me->query("name")+"真的親手擊敗黃帝病和木無言嗎!?」\n" + NOR,me);
}else{
message_vision(HIY + "天嬰說道:「總有一天我會讓天下人知道，不論英雄真經或魔界金典，都比不上我的英雄新經。」\n" + NOR,me);
}
}
}

void heart_beat()
{
object me;
int kee,mkee,sen,msen,gin,mgin,chance,ekee,egin,esen;
me=this_object();
kee=me->query("kee");
mkee=me->query("max_kee");
sen=me->query("max_sen");
msen=me->query("max_sen");
gin=me->query("max_gin");
mgin=me->query("max_gin");

if(!me->query_temp("unconcious"))
{
  if((kee < mkee || sen < msen || gin < mgin) && random(4)==1) //回精氣神
  {
message_vision(HIB + "
$N運起少林寺內功心法" + HIW + "<<" + HIM + "菩提拂拭神功" + HIW + ">>

                 " + HIW + "『" + HIY + "心如明鏡，身如菩提，時常勤拂拭，一切魔障給我破！" + HIW + "』

                               " + HIC + "$N身上的傷勢立即復原了些許\。
\n" + NOR,me);
          me->delete_busy();
          ekee=me->query("eff_kee");
          egin=me->query("eff_gin");
          esen=me->query("eff_sen");
          me->receive_curing("kee",400+(mkee-kee)/10);
          me->receive_heal("kee",400+(mkee-ekee)/10);
          me->receive_curing("gin",400+(mgin-gin)/10);
          me->receive_heal("gin",400+(mgin-egin)/10);
          me->receive_curing("sen",400+(msen-sen)/10);
          me->receive_heal("sen",400+(msen-esen)/10);
          COMBAT_D->report_status(me);
  }
  if(me->query_busy()&& random(100)<35)
  {
message_vision(HIR + "$N潛運" + HIW + "<<" + HIM + "菩提拂拭神功" + HIW + ">>" + HIR + "衝破滯塞，接著以" + HIY + "閃電步" + HIR + "迅速解除束縛。\n" + NOR,me);
          me->delete_busy();
  }
}
  if(me->query("kee")<0) me->die();
set_heart_beat(1);

::heart_beat();
}

void die()
{
object winner = query_temp("last_damage_from");
if(winner->query_temp("can_kill_baby"))
{
         message_vision(HIB + "天嬰身上掉落一本隱泛藍光的書。\n" + NOR,winner);

             winner->set_temp("ko_baby",1);
             book = new("/open/capital/obj/book.c");
             book->move(winner);
               winner->delete_temp("can_kill_baby");
               winner->set_temp("get_new",1);
}
           :: die();
}
