inherit NPC;     //無心老人 2000.4.2 by dhk
#include <ansi.h>
#include "/open/open.h"
inherit F_MASTER;
string do_god();
string do_glaze();

void create()
{
  set_name("無心老人",({"noheart oldman","noheart","oldman"}));
  set("long","    昔有神農嚐百草，今有無心老人以一身貫古絕今的製藥學術\n"
            +"，救濟天下。他就是當今世上獨一無二的『"HIY"藥神"NOR"』─\n"
            +"無心，他一肚子神奇的藥劑知識，據說至今還未有他老人家配不\n"
            +"出的藥。但是他個性孤僻，崇尚緣份說，故要找他老人家配藥者\n"
            +"數千，但是得藥者不出十人呀！\n");
  set("gender","男性"); 
  set("class","doctor");
  set("title",""HIR"毒神"HIY"藥聖"NOR"");
  set("attitude","heroism");
  set("age",435);
  set("max_kee",10000);
  set("kee",10000);
  set("max_force",10000);
  set("force",10000);
  set("force_factor",10);
  set("combat_exp",3500000);
  set("inquiry",([
  "藥神" : (:do_god:),
  "雙麒麟火琉璃" : (:do_glaze:),
  ]));
  setup();
}
void init()
{
        add_action("do_answer","answer");
set_heart_beat(1);
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
                else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
        :: heart_beat();
}
string do_god()
{
        object me=this_player();
        if(me->query("family/family_name")=="段家")
        {
         me->set_temp("dhk_glaze",1);
               return("哈哈哈！！！\n"+"最近我的運氣真不錯，不但配出一帖奇藥，還無意間得到一樣珍寶\n"+"『"HIC"雙麒麟"HIR"火琉璃"CYN"』真是幸運呀！哈哈哈！！！"NOR"\n");
}
else
{
command("?");
return("我只是一名孤苦伶仃的老人呀！");
}
}

int do_answer(string str)
{
  object me=this_player();
  object glaze=new("/open/ping/questsfan/obj/glaze.c");
  string *answer = ({
        "金創藥",
        "越橘藥",
        "三味甘露丹",
        "九轉金丹",
        "黃蓮解毒散",
        "二龍補心丹",
        "神龍百足散",
        "牛黃活竅散",
        "白雲紫心丹",
        "六合反精散",
        "回生續命丹",
        "九轉熊蛇丸",
        "生生造化丹"
  });
//已經修復會一直給東西的bug
   if(!me->query_temp("answer"));
  else
  {
   if(str == answer[me->query_temp("answer")])
    {
     command("pat "+me->query("id"));
     write(""HIY"很好"NOR"﹐" + RANK_D->query_respect(me) + ""CYN"的藥學常識不錯, 值得嘉許\他日必能在江湖上揚名立姓。"NOR"\n");
     command("recruit " + me->query("id") );
     write(""CYN"嗯..既然你我有緣那我就把日前得到的『"HIC"雙麒麟"HIR"火琉璃"CYN"』贈與你吧！"NOR"\n");
//_________送物________//
    glaze->move(me);
command("smile "+me->query("id"));
      }
          else
          {
            command("sigh "+me->query("id"));
            write(RANK_D->query_respect(me)+""CYN"你的藥學常識太膚淺了, 也許\應該多去研究研究醫理,下次有緣了再見吧！！！"NOR"\n");
          }
          me->delete_temp("answer");
        }
        return 1;
}

string do_glaze()
{
       object me=this_player();
        int which;
        string *question = ({
      ""WHT"硼砂"NOR"┼"YEL"蒲黃"NOR"",
      "大蒜┼"HIB"陳皮"NOR"",
      ""RED"當歸"NOR"┼"HIR"紅花"NOR"┼"HIC"人蔘"NOR"",
      ""RED"當歸"NOR"┼"HIC"人蔘"NOR"┼"HIG"冬蟲夏草"NOR"",
      ""HIY"黃蓮"NOR"┼"HIY"黃笒"NOR"",
      ""HIY"九轉熊蛇丸"NOR"┼"HIC"順氣丹"NOR"",
      ""HIM"田七"NOR"┼"RED"蜈蚣"NOR"",
      ""HIY"牛黃"NOR"┼"RED"蜈蚣"NOR"",
      ""HIM"紫背天葵"NOR"┼曇花",
      ""HIY"牛黃"NOR"┼"HIY"黃蓮"NOR"┼樟腦",
      ""RED"當歸"NOR"┼"HIC"人蔘"NOR"┼珍珠",
      ""HIY"九葉金蘭"NOR"┼"CYN"熊膽"NOR"┼"HIG"龍舌草"NOR"",
      ""HIG"長生草"NOR"┼"HIR"化氣紅蓮"NOR"┼長白山雪水"
        });
        if(me->query_temp("dhk_glaze")==1)
       {
        which=random(sizeof(question));
        if(me->query_temp("have_med"))
          write("怎麼這麼快又見面了? 下次再來吧。\n");
        else
        {
        write(" "+RANK_D->query_respect(me)+""CYN"想要雙麒麟火琉璃嗎？\n"+"若我們沒有一定的緣份, 那就抱歉了。\n"+"老夫這就來試一試你, 看看你我是否有緣，準備回答("HIW"answer"CYN")我的問題吧！"NOR"\n");
write("無心老人緩緩的說道:"+question[which]+"\n");
        write(""CYN"無心老人和藹的說道: 你能說說這些藥材所能配出的藥名嗎?"NOR"\n");
        me->set_temp("have_med",1);
       me->set_temp("answer",which);
        }
        }
        else
        return("你問那麼多幹嘛….?");
}

