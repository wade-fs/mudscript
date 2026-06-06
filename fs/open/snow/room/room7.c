//強調解謎的關鍵字 by blazakira

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
  string long; //設定為文字變數
  set("short",HIY + "藏經閣" + NOR);
  long = "這裡是雪蒼派的藏經閣，裡面所放的都是雪蒼派的秘笈，但是一\n"
"般的弟子，在沒經過掌門" + HIG + "准許\" + NOR + "，是不得動裡面的書籍，在門口有一張\n"
"藏經閣的藏書表(list)，只有經過掌門" + HIG + "准許\" + NOR + "的人才能在此研讀裡面的\n"
"藏書。\n";
  set("long", long);

/*  set("long",@LONG
這裡是雪蒼派的藏經閣，裡面所放的都是雪蒼派的秘笈，但是一
般的弟子，在沒經過掌門准許，是不得動裡面的書籍。在門口有一張
藏經閣的藏書表(list)，只有經過掌門准許的人才能在此研讀裡面的
藏書。
LONG);*/
  set("exits", ([
    "west":__DIR__"room6",
    ]) );
  set("light_up",1);
  set("objects",([
  "/open/snow/obj/book":1,
  ]));
  setup();
}
void init()
{
  add_action("do_list","list");
  add_action("do_study","read");
}
int do_list()
{
  string long;
  object me=this_player();
  long=WHT + "  這裡的藏書有：\n"
       HIW + "      雪蒼秘錄 (Snow book)\n"
       HIW + "      狂風鬼影腳秘笈 (feet book)\n"
       HIW + "      枯\葉殘風錄 (star book)\n"
       WHT + "      雪影幻指(ice-fingers)\n"
       WHT + "      凌霜奇訣(snow-powerup)\n" + NOR;
  tell_object(me,long);
/*  tell_object(me,@LONG
  這裡的藏書有﹕
      雪蒼秘錄 (Snow book)
      狂風鬼影腳秘笈 (feet book)
      枯葉殘風錄 (star book)
      雪影幻指(ice-fingers)
      凌霜奇訣(snow-powerup)
LONG);*/
  return 1;
}
int do_study(string str)
{
   object me=this_player();
   string in_skill;
   int amount;
   if(this_player()->query("allow_study")!=1)
          return notify_fail("你不能亂動這裡的書。\n");
   if(str=="snow book") { in_skill="quests/read_snow"; amount=1; }
   if(str=="feet book") { in_skill="quests/read_snow"; amount=2; }
   if(str=="star book") { in_skill="quests/read_snow"; amount=3; }
   if(str=="ice-finger") {
      tell_object(me,@LONG
雪影幻指乃是雪蒼武學的最高境界，練成雪影幻指者，身形如風
可控制體內氣流，轉化成強勁之寒氣，雪蒼派歷代練成者只有八人，
此八人皆揚名武林，成為一代高手，全書手撰此書之意，僅在言明雪
蒼武學精奧之處。
 
  
                                      雪蒼派第四代  劉全書
LONG);
            return 1;
      }
     if(str=="snow-powerup")
       {
          tell_object(me,@LONG
凌霜奇訣乃我雪蒼護身氣勁之絕學，武功高者可將內力凝結，轉
而發出數倍內勁，是我派至高之絕學，也是武學中之一大突破，此為
劉全書在玄天聖谷中苦思一年所創，配合雪影幻指便成為武林中首屈
一指的絕學。
   
                                雪蒼派第四代  劉全書
LONG); 
        return 1;
       }
     if(me->query("quests/read_snow")>=1)
    {
        tell_object(me,"你已經研讀過三本秘笈中的一本，已不准再讀。\n");
        return 1;
    }
    tell_object(me,"你研讀之後，使你對武學更有所領悟。\n");
    if(in_skill)
    {
    me->set(in_skill,amount);
    me->set("title","雪蒼絕學傳人");
    }
   return 1;
}
