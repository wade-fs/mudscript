//posthumous_paper......  by dhk 2000.5.12
#include <ansi.h>


inherit BOOK;

#define BOOK_PATH "/u/d/dhk/questsfan/obj/"
#define BOOK_NAME "posthumous"
#define BOOK_NAME1 "posthumous1"
#define C_BOOK_NAME ""HIR"沾血的遺書"NOR""

void create()
{
  ::create();
  set_name( C_BOOK_NAME, ({ "posthumous" }) );
  set( "long", "這是一張是無名前輩所寫的遺書，你可以用(read)來觀看。\n");
  set ( "value", ({ 10, "silver" }) );   //價值
  set ( "book_path", BOOK_PATH + BOOK_NAME );
  setup();
}

int do_read(string arg)
{
       object me = this_player();
       int level=(int)(me->query_skill("literate",1));
       int sun=(int)(me->query_skill("sunforce",1));
        if(level >= 120 && sun >=120 )
       {
       me->set_temp("buy_ok",1);
       cat( sprintf(__DIR__"posthumous") );
tell_object(me,"當你一看"HIR"沾血的遺書"NOR"後，忽然氣血翻騰、真氣逆衝。\n\n");
tell_object(me,""HIR"你的眼前一黑，接著什麼也不知道了...."NOR"\n\n");
me->set_temp("can_not_do_anything",1);
  tell_object(me,"你忽然領悟了"HIC"北冥神功\"NOR"中的"HIM"『北冥回朔法』"NOR"，心隨神移。\n\n");
tell_object(me,"就在你迷迷糊糊之中，你忽然見到一位面如冠玉、超凡脫俗\n"
              +"的青年男子。接著他開口說話了，他說道：『欲過虹晶橋，\n"
              +"只有在每一個時辰之一刻、兩刻、三刻鐘以及下一個時辰來\n"
              +"臨前的五分鐘而已，理由是在這些時刻三座晶橋會因日、月\n"
              +"光的照射下，產生全反射，而導致兩座蜃影晶橋消失無蹤。\n"
              +"但是若要在其他時間硬闖，根據我的觀察，虹晶橋更替的狀\n"
              +"況依然有一定的規則，就是以現在的時辰置日晷，觀其分影\n"
              +"。因為這裡的三光每一刻五分交輝..我就把我的經驗告訴你\n"
             +"....若日晷的影子在正四方時：\n"
             +"      我試過在三時一刻兩分真實的晶橋位置在正北方那座\n"
             +"      我試過在六時兩刻一分真實的晶橋位置在西北方那座\n"
             +"      我試過十二時三刻六分真實的晶橋位置在東北方那座\n"
             +"....若日晷的影子只差三十度就到正四方時：\n"
             +"      我試過在四時一刻七分真實的晶橋位置在西北方那座\n"
             +"      我試過在十時兩刻五分真實的晶橋位置在東北方那座\n"
             +"      我試過十六時三刻三分真實的晶橋位置在正北方那座\n"
             +"....若日晷的影子只差十五度就到正四方時：\n"
             +"      我試過在八時一刻九分真實的晶橋位置在東北方那座\n"
             +"      我試過十一時兩刻六分真實的晶橋位置在正北方那座\n"
             +"      我試過十七時三刻零分真實的晶橋位置在西北方那座\n"
             +"還有小心雙五見閻王.....\n"
              +"唉！我言盡於此...』\n"
              +"漸漸地！！！\n"
              +"漸漸地！！！\n");
tell_object(me,"那青年的身影漸漸模糊，消失了。\n\n");
tell_object(me,""HIY"慢慢地你終於又有了知覺...."NOR"\n\n");
me->set_temp("can_not_do_anything",0);       
tell_object(me,"這一切宛如作夢一般。\n");
       return 1;
       }
       else
       if(level >= 90 )
       {
       me->set_temp("buy_ok",1);
       cat( sprintf(__DIR__"posthumous") );
       return 1;
       }
       else
       tell_object(me,"你左看右看就是看不懂這張的內容，看來要再去進修進修囉!!!\n");
       return 1;

}

