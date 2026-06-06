inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIY + "金之封印石" + NOR,({"gold fon stone","stone"}));
        set("long","一個封印著神兵利器的神秘石頭，上面有著數個大大小小不等的\n"
                  +"奇形怪洞，應該可以放入解開封印的物品，若想要得到封印的神\n"
                  +"兵，可以將你所得到的解封印的物品(insert)進去，就可以讓神\n"
                  +"兵神器重新現世。\n");
        set("unit","尊");
        set("value",100);
        set("no_get",1);
        set("no_sac",1);
        set("no_auc",1);
        set_weight(500000);
        setup();
}

void init()
{
        add_action("do_insert","insert");
}

int do_insert(string str)
{
        object ob=this_object(),me=this_player();

        if( !str )
        return 0;

        switch(str)
        {
        case "sky-stone":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("sky")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n" + NOR,me,present(str,me));
        ob->set("sky",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "loyal-stone":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("loyal")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n" + NOR,me,present(str,me));
        ob->set("loyal",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "peace-stone":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("peace")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n" + NOR,me,present(str,me));
        ob->set("peace",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "emperor-stone":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("emperor")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n" + NOR,me,present(str,me));
        ob->set("emperor",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "soil-stone":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("soil")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n" + NOR,me,present(str,me));
        ob->set("soil",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "justice-stone":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("justice")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n" + NOR,me,present(str,me));
        ob->set("justice",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "charity-stone":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("charity")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n" + NOR,me,present(str,me));
        ob->set("charity",1);
        destruct(present(str,me));
        call_out("check",3,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        default:

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        message_vision("$N似乎想放什麼東西，但卻找不到正確的位置放!!\n",me);
        break;
        }
        return 1;

}

int check(object ob)
{
        ob->add("check",1);

        if(ob->query("check") == 7 )
        {
        tell_object(users(),HIC + "\n\n\t大地忽然劇烈地憾動了起來，在極遠處的一座山頂上落下了數道的閃電!!\n" + NOR);
        tell_object(users(),HIC + "\n\t遠處的閃電七彩繽紛，輕輕地劃過了天際，劃亮了整個天空!!\n" + NOR);
        tell_object(users(),HIC + "\n\t雷聲憾動了天地，飛鳥走獸們都慌忙的飛奔走散!!\n" + NOR);
        call_out("msg1",5,ob);
        }
        return 1;
}

int msg1(object ob)
{
        object me=this_player();
        tell_object(users(),HIC + "\n\n\t在天靈地界中的" + HIY + "金之封印石" + HIC + "因為"HIG+ me->query("name")+HIC"的努力而解開了!!\n" + NOR);
        tell_object(users(),HIC + "\n\t因為失去了神力護持的" + HIY + "金之封印石" + HIC + "開始劇烈抖動而開始崩散消逝!!\n" + NOR);
        call_out("msg2",5,ob);
        return 1;
}

int msg2(object ob)
{
        object me=this_player(),room=environment(me);
        tell_object(users(),HIC + "\n\n\t在天靈地界塵封已久的" + HIM + "「金風舞夢旋」"NOR+HIC"從" + HIY + "金之封印石" + HIC + "中得到了解放而現世了!!\n" + NOR,ob);
        message_vision(HIW + "\n\t七顆解開封印的智石轉化為七束光茫，緩緩注入了" + HIM + "「金風舞夢旋」"NOR+HIW"之中轉化為不可思議的力量!!\n",ob);
        message_vision(HIW + "\n\t光茫消散之後" + HIM + "「金風舞夢旋」"NOR+HIW"緩緩凝聚在$N手中!!\n" + NOR,me);
        new("/autoload/sky/golden_wind")->move(me);
        write_file("/log/sky/goldfon",sprintf("%s(%s) 解開了「金風舞夢旋」於 %s\n",me->name(1),me->query("id"),ctime(time())));
        room->set("no_reset",1);
        destruct(ob);
        return 1;
}
