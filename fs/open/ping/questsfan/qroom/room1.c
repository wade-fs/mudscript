#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "虹晶橋前段");
  set ("long", @LONG
你見到三座豪光奪目，華麗不凡的晶橋。橋全長約百
步之遠、寬僅可供一人通行而已。橋上全無纜繩之類的扶
手，均需靠自身的平衡感及千斤墜造詣來通行。在右前方
處有一石碑，碑上記載著密密麻麻的甲骨文字，深奧難懂
，似是有關此橋的由來。

LONG);

        set("exits", ([ /* sizeof() == 1 */
  "north" : __FILE__,
  "south" : __DIR__"room0",

]));
set("no_transmit", 1);
        set("objects", ([
]));
        setup();
}
void init()
{
        object me=this_player();
        string nowtime,nowmin,nowhour,nowday,rightway;
        int min,hour,day,trueroad;

        nowtime=ctime(time());
        nowmin=nowtime[14..15];
        nowhour=nowtime[11..12];
        nowday=nowtime[8..9];
        if(sscanf(nowmin,"%d",min))
                min=min;
        if(sscanf(nowhour,"%d",hour))
                hour=hour;
        if(sscanf(nowday,"%d",day))
                day=day;
        switch(hour%3)
        {
                case 0:
                        trueroad=1;
                        break;
                case 1:
                        trueroad=2;
                        break;
                case 2:
                        trueroad=3;
                        break;
                default:
                        write("出現bug囉!!\n");
                        break;
        }
        if(wizardp(me))
        {
        printf(HIY"現在時間 "+ctime(time())+"\n"NOR);
        printf(HIY"分為%d分\n"NOR,min);
        printf(HIY"時辰為%d點\n"NOR,hour);
        printf(HIY"日期為%d日\n"NOR,day);
        printf("trueroad=%d\n",trueroad);
        }
        switch(trueroad)
        {
                case 1:
                        if(min==15)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room2");
                                rightway="north";
                        }
                        if(min>=0 && min<=20 && min!=15)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room2");
                                set("exits/northwest",__DIR__"room3");
                                set("exits/northeast",__DIR__"room4");
                                rightway="north";
                        }
                        if(min>=21 && min<=40)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room4");
                                set("exits/northwest",__DIR__"room2");
                                set("exits/northeast",__DIR__"room3");
                                rightway="northwest";
                        }
                        if(min>=41 && min<=59)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room3");
                                set("exits/northwest",__DIR__"room4");
                                set("exits/northeast",__DIR__"room2");
                                rightway="northeast";
                        }
                        break;
                case 2:
                        if(min==35)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room2");
                                rightway="north";
                        }
                        if(min>=0 && min<=20)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room4");
                                set("exits/northwest",__DIR__"room2");
                                set("exits/northeast",__DIR__"room3");
                                rightway="northwest";
                        }
                        if(min>=21 && min<=40 && min!=35)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room3");
                                set("exits/northwest",__DIR__"room4");
                                set("exits/northeast",__DIR__"room2");
                                rightway="northeast";
                        }
                        if(min>=41 && min<=59)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room2");
                                set("exits/northwest",__DIR__"room3");
                                set("exits/northeast",__DIR__"room4");
                                rightway="north";
                        }
                        break;
                case 3:
                        if(min==55)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room2");
                                rightway="north";
                        }
                        if(min>=0 && min<=20)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room3");
                                set("exits/northwest",__DIR__"room4");
                                set("exits/northeast",__DIR__"room2");
                                rightway="northeast";
                        }
                        if(min>=21 && min<=40)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room2");
                                set("exits/northwest",__DIR__"room3");
                                set("exits/northeast",__DIR__"room4");
                                rightway="north";
                        }
                        if(min>=41 && min<=59 && min!=55)
                        {
                                delete("exits");
                                set("exits/south",__DIR__"room0");
                                set("exits/north",__DIR__"room4");
                                set("exits/northwest",__DIR__"room2");
                                set("exits/northeast",__DIR__"room3");
                                rightway="northwest";
                        }
                        break;
        }
        if(wizardp(me))
                printf("正確的路為%s\n",rightway);
//add by bss,解過的人怕死,所以解過的可以用飛的
    if(me->query("marks/fan-finger"))
      tell_object(me,HIM"你對於你的輕功\充滿了信心, 似乎可以飛渡(fly)懸涯!!\n"NOR);
      add_action("do_fly","fly");
}
int do_fly()
{
    object me=this_player();
    int i;
     
    message_vision(HIY"$N使出絕頂輕功\, 用力一跳, 往對岸飛去!!!\n"NOR,me);
    if(me->query("marks/fan-finger")){
      me->move("/open/ping/questsfan/qroom/room5");
      message_vision(HIC"$N在空中翻了三個筋斗, 輕輕的落在地上!!\n"NOR,me);
    }
    else{
      message_vision(HIR"$N在空中忽然感到真氣不足, 一個不留神, 往下摔去!!\n"NOR,me);
      if(sizeof(this_object()->query("exits")) > 2) i=random(50);
      else i=2;
      switch(i){
        case 0..5:
          me->move("/open/ping/questsfan/qroom/room2");
          tell_object(me,HIM"碰的一聲, 你掉到了橋上, 真是好險!!\n"NOR);
          break;
        default:
          me->move("/open/ping/questsfan/qroom/room3");
          tell_object(me,HIG"眼看你就要掉到橋上了, 但是你忽然發現, 那個橋竟然是幻影!!\n"NOR);
          break;
      }
    }
    return 1;
}

