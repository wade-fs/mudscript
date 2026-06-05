// look.c

#include <room.h>
#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;
inherit SECURITY_D;

#define EXIT ({ "north", "south", "east", "west", "up", "down", "enter", "out",    "northeast", "northwest", "southeast", "southwest" })
int look_room( object me, object env, int light );
int look_item( object me, object obj );
int look_living( object me, object obj );
int look_room_item( object me, string arg );

string fuzzy_long( string long );
string power_level(int power);

string *power_level_desc = ({
        BLU + "不堪一擊" + NOR,
        BLU + "不足挂齒" + NOR,
        BLU + "初學乍練" + NOR,
        BLU + "略窺門徑" + NOR,
        BLU + "粗通皮毛" + NOR,
        BLU + "平平常常" + NOR,
        HIB + "普普通通" + NOR,
        HIB + "馬馬虎虎" + NOR,
        HIB + "略有小成" + NOR,
        HIB + "舉重若輕" + NOR,
        HIB + "駕輕就熟" + NOR,
        HIB + "已有小成" + NOR,
        CYN + "心領神會" + NOR,
        CYN + "了然於胸" + NOR,
        CYN + "略有大成" + NOR,
        CYN + "出神入化" + NOR,
        CYN + "豁然貫通" + NOR,
        CYN + "已有大成" + NOR,
        CYN + "舉輕若重" + NOR,
        CYN + "所向披靡" + NOR,
        HIC + "爐火純青" + NOR,
        HIC + "所向無敵" + NOR,
        HIC + "登峰造極" + NOR,
        HIC + "一代宗師" + NOR,
        HIC + "震今鑠古" + NOR,
        HIR + "天人合一" + NOR,
        HIW + "深不可測" + NOR,

});

void create() { seteuid(getuid()); }

int main( object me, string arg )
{
    object    obj, env;
    int    result, can_see;

    can_see = NATURE_D->vision(me);
    env = environment(me);

    if( arg )
        arg = lower_case(arg);
    if( arg && member_array( arg, EXIT ) != -1 &&
        member_array( geteuid(me), EXIT ) != -1 )
        return look_room_item( me, arg );
    if( !arg )
        result = look_room( me, env, can_see );
    else if( (obj = present( arg, me) ) || ( obj = present( arg, environment(me) ) ) ) {
        if( obj->is_character() )
            result = look_living(me, obj);
        else
            result = look_item( me, obj );
    }
    else
        result = look_room_item(me, arg);
    return result;
}

int look_room( object me, object env, int light )
{
    int           i;
    object        *inv;
    mapping       exits;
    string        str, *dirs, tmp;

    if( light == 0 )
        return notify_fail( "四周到處黑沉沉的, 看也看不清。\n" );
    if( me->query_temp("brief_mode") )
        str = sprintf( "%s - %s%s\n",
            env->short(),
            env->query("owner")? "("+capitalize(env->query("owner"))+")" : "",
            wizardp(me)? file_name(env) : ""
            );
    else {
        tmp = env->query("long");
        str = sprintf( "%s - %s%s\n    %s%s",
            env->short(),
            env->query("owner")? "("+capitalize(env->query("owner"))+")" : "",
            wizardp(me)? file_name(env) : "",
            tmp,
            env->query("outdoors") ? NATURE_D->outdoor_room_description() : ""
            );
    }

    if( light == -1 )
        str += "    四周到處模模糊糊的, 看也看不清出口。\n";
    else
    if( mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++){
            if( (int)env->query_door(dirs[i], "status") != 0 )
                dirs[i] = 0;
            else if(me->query("env/mxp"))
            {
              dirs[i] =  "<send>"+dirs[i]+"</send>";
            }
        }
        dirs -= ({ 0 });
        if( sizeof(dirs)==0 )
            str += "    這裡沒有任何明顯的出路。\n";
        else if( sizeof(dirs)==1 )
            str += "    這裡唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
        else
            str += sprintf("    這裡明顯的出口是 " + BOLD + "%s" + NOR +
                " 和 " + BOLD + "%s" + NOR + "。\n",
        implode( dirs[0..sizeof(dirs)-2], "、" ), dirs[sizeof(dirs)-1] );
    }
    tmp = env->door_description();
    if (tmp)
        str += env->door_description();
    inv = all_inventory(env);
    for(i=0; i<sizeof(inv); i++) {
        string short_name ;
        if( (string)inv[i]->query("env/invis")=="YES" && wiz_level(inv[i]) > wiz_level(me) )
            continue;
       if( (string)inv[i]->query("env/隱身")=="YES" && wiz_level(inv[i]) > wiz_level(me) )
            continue;
        if( inv[i]->query_temp("invis") && !wizardp(me) )
            continue;
        // 隱身的效果
        if( !wizardp(me) && inv[i]->query("inv") > me->query_temp("inv") )
        {
            if(inv[i]->query("inv") - me->query_temp("inv") < 20)
                str += "  一個模糊不清的身影。\n";
            continue;
        }
        short_name = inv[i]->short() ;
        if(me->query("env/mxp")) {
          short_name = replace_string(short_name,"(","(<send \"look &text;|fight &text;|kill &text;|consider &text;\">");
          short_name = replace_string(short_name,")","</send>)");
        }
        if( inv[i]==me )
            continue;
        if( light==-1 ) {
            if( random(2) )
                str += "  " + short_name + "\n";
        }
        else
//現在狀態有點偏多，會造成人物的名字加上狀態一長串，暫時拿掉。
//暫時加在下方的look_living裏面。
//            str += "  " + CON_D->con_query(inv[i]) + inv[i]->short() + "\n";
          if( userp(inv[i])) str += BLK + "[*] " + NOR ;
          else if( inv[i]->query("inquiry")) str += WHT + "[Q] " + NOR ;
          else str +=  "    " ;

          str +=  short_name + "\n";


    }
//    tell_object( me, trans_color(str) );
    str = ESC+"[6z"+ansi(str) +ESC +"[0z";
    tell_object( me, str);
    return 1;
}

int look_item(object me, object obj)
{
  string        msg;
  mixed         *inv;

  msg = obj->long();

  inv = all_inventory(obj);
  if( sizeof(inv) ) {
    inv = map_array(inv, "inventory_look", this_object() );
    msg += sprintf("裡面有﹕\n  %s\n", implode(inv, "\n  "));
  }

  me->start_more(msg);
  return 1;
}

string getper(object me, object obj)
{
        int per;
        int inte;
    int weight;
        string str;
        per = obj->query_per();
        inte = me->query_int();
//        if(obj->query_temp("add_per"))
//        {per = obj->query_per()+obj->query_temp("add_per");}
        // 悟性差的人看的不準
    if (inte > 30) weight = 0;
        else weight = (int)(30-inte)/4;

        if (random(10)>6) per = per - random(weight);
        else per = per + random(weight);
        
        if ((string) obj->query("gender") == "男性") 
        {
      if( obj != me )
      {
        if(obj->query("age")<18)
        {
          if(per >=25) str = CYN + "他星眸皓齒，面貌清俊。\n" + NOR;
          if(per <25 && per >=20) str = CYN + "他膚色白皙，斯文有禮。\n" + NOR;
          if(per <20 && per >= 15) str = CYN + "他黑髮披肩，面貌端正。\n" + NOR;
          if(per <15 && per >=10)str = CYN + "他肥頭大耳，小鼻小眼。\n" + NOR;
          if(per <10)str = CYN + "他面色青黃，尖嘴猴腮。\n" + NOR;
        }
        if(obj->query("age")>=18 && obj->query("age")<40)
        {
          if (per >= 30) str = CYN + "他丰姿英偉，堪稱人中龍鳳。\n" + NOR;
          if ((per == 29)||(per == 28)) str = CYN + "他英俊瀟洒，貌似潘安。\n" + NOR;
          if ((per == 27)||(per == 26)) str = CYN + "他劍眉星目，英姿勃勃。\n" + NOR;
          if ((per == 25)||(per == 24)) str = CYN + "他相貌出眾，百里挑一。\n" + NOR;
          if ((per == 23)||(per == 22)) str = CYN + "他面貌清奇，丰姿非俗。\n" + NOR;
          if ((per == 21)||(per == 20)) str = CYN + "他眉目清秀，氣宇軒昂。\n" + NOR;
          if ((per == 19)||(per == 18)) str = CYN + "他儀表不凡，面目俊朗。\n" + NOR;
          if ((per == 17)||(per == 16)) str = CYN + "他鼻直口方，五官端正。。\n" + NOR;
          if ((per == 15)||(per == 14)) str = CYN + "他瘦骨伶仃，相貌平平。\n" + NOR;
          if ((per == 13)||(per == 12)) str = CYN + "他五短身材，肥頭大耳。\n" + NOR;
          if ((per == 11)||(per == 10)) str = CYN + "他相貌凶惡，滿臉橫肉。\n" + NOR;
          if (per <= 9) str = CYN + "他賊眉鼠眼，面目可憎。\n" + NOR;
          if (per < 5)  str = CYN + "他五官錯位，面目猙獰。\n" + NOR;
        }
        if(obj->query("age")>=40)
        {
          if(per >=25) str = CYN + "他丰姿英偉，氣宇軒昂。\n" + NOR;
          if(per <25 && per >=20) str = CYN + "他面貌清奇，神采飛揚。\n" + NOR;
          if(per <20 && per >=15) str = CYN + "他鼻直口方，五官端正。\n" + NOR;
          if(per <15 && per >=10)str = CYN + "他面色槁枯\，皺紋堆累。\n" + NOR;
          if(per <10 && per >=5)str = CYN + "他犬眼鷹鼻，面目猙獰。\n" + NOR;
          if(per <5)str = CYN + "他口眼歪斜，人見人憎。\n" + NOR;
        }
      }else{
        if(obj->query("age")<18)
        {
          if(per >=25) str = CYN + "你星眸皓齒，面貌清俊。\n" + NOR;
          if(per <25 && per >=20) str = CYN + "你膚色白皙，斯文有禮。\n" + NOR;
          if(per <20 && per >= 15) str = CYN + "你黑髮披肩，面貌端正。\n" + NOR;
          if(per <15 && per >=10)str = CYN + "你肥頭大耳，小鼻小眼。\n" + NOR;
          if(per <10)str = CYN + "你面色青黃，尖嘴猴腮。\n" + NOR;
        }
        if(obj->query("age")>=18 && obj->query("age")<40)
        {
          if (per >= 30) str = CYN + "你丰姿英偉，堪稱人中龍鳳。\n" + NOR;
          if ((per == 29)||(per == 28)) str = CYN + "你英俊瀟洒，貌似潘安。\n" + NOR;
          if ((per == 27)||(per == 26)) str = CYN + "你劍眉星目，英姿勃勃。\n" + NOR;
          if ((per == 25)||(per == 24)) str = CYN + "你相貌出眾，百裡挑一。\n" + NOR;
          if ((per == 23)||(per == 22)) str = CYN + "你面貌清奇，丰姿非俗。\n" + NOR;
          if ((per == 21)||(per == 20)) str = CYN + "你眉目清秀，氣宇軒昂。\n" + NOR;
          if ((per == 19)||(per == 18)) str = CYN + "你儀表不凡，面目俊朗。\n" + NOR;
          if ((per == 17)||(per == 16)) str = CYN + "你鼻直口方，五官端正。\n" + NOR;
          if ((per == 15)||(per == 14)) str = CYN + "你瘦骨伶仃，相貌平平。\n" + NOR;
          if ((per == 13)||(per == 12)) str = CYN + "你五短身材，肥頭大耳。\n" + NOR;
          if ((per == 11)||(per == 10)) str = CYN + "你相貌凶惡，滿臉橫肉。\n" + NOR;
          if (per <= 9) str = CYN + "你賊眉鼠眼，面目可憎。\n" + NOR;
          if (per < 5)  str = CYN + "你五官錯位，面目猙獰。\n" + NOR;
        }
        if(obj->query("age")>=40)
        {
          if(per >=25) str = CYN + "你丰姿英偉，氣宇軒昂。\n" + NOR;
          if(per <25 && per >=20) str = CYN + "你面貌清奇，神采飛揚。\n" + NOR;
          if(per <20 && per >= 15) str = CYN + "你鼻直口方，五官端正。\n" + NOR;
          if(per <15 && per >=10)str = CYN + "你面色槁枯\，皺紋堆累。\n" + NOR;
          if(per <10 && per >=5)str = CYN + "你犬眼鷹鼻，面目猙獰。\n" + NOR;
          if(per <5)str = CYN + "你口眼歪斜，人見人憎。\n" + NOR;
        }
      }
    }
    if ((string) obj->query("gender") == "女性")
    {
      if ( obj != me )
      {
        if(obj->query("age")<18)
        {
          if(per >=25) str = MAG + "她冰清玉潔，容顏嬌美。\n" + NOR;
          if(per <25 && per >=20) str = MAG + "她膚色白皙，眉清目秀。\n" + NOR;
          if(per <20 && per >= 15) str = MAG + "她秀髮披肩，容貌端正。\n" + NOR;
          if(per <15 && per >=10)str = MAG + "她身材瘦小，胸部平平。\n" + NOR;
          if(per <10)str = MAG + "她身材矬矮，滿臉雀斑。\n" + NOR;
        }
        if(obj->query("age")>=18 && obj->query("age")<40)
        {
          if (per >= 30) str = MAG + "她美奐絕倫，如月中嫦娥。\n" + NOR;
          if ((per == 29)||(per == 28)) str = MAG + "她玉雪冰肌，如瑤池仙子。\n" + NOR;
          if ((per == 27)||(per == 26)) str = MAG + "她秀髮如柒，有沉魚落雁之容。\n" + NOR;
          if ((per == 25)||(per == 24)) str = MAG + "她冰清玉潔，有閉月羞花之貌。\n" + NOR;
          if ((per == 23)||(per == 22)) str = MAG + "她風情萬種，楚楚動人。\n" + NOR;
          if ((per == 21)||(per == 20)) str = MAG + "她柳眉杏目，容貌嬌艷。\n" + NOR;
          if ((per == 19)||(per == 18)) str = MAG + "她皓齒紅顏，俏臉生春。\n" + NOR;
          if ((per == 17)||(per == 16)) str = MAG + "她眉清目秀，萬種柔情。\n" + NOR;
          if ((per == 15)||(per == 14)) str = MAG + "她身材適中，胸部平平。\n" + NOR;
          if ((per == 13)||(per == 12)) str = MAG + "她身寬體胖，手肥腳大。\n" + NOR;
          if ((per == 11)||(per == 10)) str = MAG + "她身材矬矮，一頭亂髮。\n" + NOR;
          if (per <= 9) str = MAG + "她髮如枯\草，面目可憎。\n" + NOR;
          if (per < 5)  str = MAG + "她五官錯位，口歪眼斜。\n" + NOR;
        }
        if(obj->query("age")>=40)
        {
          if(per >=25) str = MAG + "她氣質如蘭，風華絕代。\n" + NOR;
          if(per <25 && per >=20) str = MAG + "她華髮飄飄，青春永駐。\n" + NOR;
          if(per <20 && per >= 15) str = MAG + "她徐娘半老，風韻猶存。\n" + NOR;
          if(per <15 && per >=10)str = MAG + "她面色槁枯\，皺紋堆累。\n" + NOR;
          if(per <10)str = MAG + "她雞皮鷹爪，面目猙獰。\n" + NOR;
        }
      }else{
        if(obj->query("age")<18)
        {
          if(per >=25) str = MAG + "妳冰清玉潔，容顏嬌美。\n" + NOR;
          if(per <25 && per >=20) str = MAG + "妳膚色白皙，眉清目秀。\n" + NOR;
          if(per <20 && per >= 15) str = MAG + "妳秀髮披肩，容貌端正。\n" + NOR;
          if(per <15 && per >=10)str = MAG + "妳身材瘦小，胸部平平。\n" + NOR;
          if(per <10)str = MAG + "妳身材矬矮，滿臉雀斑。\n" + NOR;
        }
        if(obj->query("age")>=18 && obj->query("age")<40)
        {
          if (per >= 30) str = MAG + "妳美奐絕倫，如月中嫦娥。\n" + NOR;
          if ((per == 29)||(per == 28)) str = MAG + "妳玉雪冰肌，如瑤池仙子。\n" + NOR;
          if ((per == 27)||(per == 26)) str = MAG + "妳秀髮如柒，有沉魚落雁之容。\n" + NOR;
          if ((per == 25)||(per == 24)) str = MAG + "妳冰清玉潔，有閉月羞花之貌。\n" + NOR;
          if ((per == 23)||(per == 22)) str = MAG + "妳風情萬種，楚楚動人。\n" + NOR;
          if ((per == 21)||(per == 20)) str = MAG + "妳柳眉杏目，容貌嬌艷。\n" + NOR;
          if ((per == 19)||(per == 18)) str = MAG + "妳皓齒紅顏，俏臉生春。\n" + NOR;
          if ((per == 17)||(per == 16)) str = MAG + "妳眉清目秀，萬種柔情。\n" + NOR;
          if ((per == 15)||(per == 14)) str = MAG + "妳身材適中，胸部平平。\n" + NOR;
          if ((per == 13)||(per == 12)) str = MAG + "妳身寬體胖，手肥腳大。\n" + NOR;
          if ((per == 11)||(per == 10)) str = MAG + "妳身材矬矮，一頭亂髮。\n" + NOR;
          if (per <= 9) str = MAG + "妳髮如枯\草，面目可憎。\n" + NOR;
          if (per < 5)  str = MAG + "妳五官錯位，口歪眼斜。\n" + NOR;
        }
        if(obj->query("age")>=40)
        {
          if(per >=25) str = MAG + "妳氣質如蘭，風華絕代。\n" + NOR;
          if(per <25 && per >=20) str = MAG + "妳華髮飄飄，青春永駐。\n" + NOR;
          if(per <20 && per >= 15) str = MAG + "妳徐娘半老，風韻猶存。\n" + NOR;
          if(per <15 && per >=10)str = MAG + "妳面色槁枯\，皺紋堆累。\n" + NOR;
          if(per <10)str = MAG + "妳雞皮鷹爪，面目猙獰。\n" + NOR;
        }
      }
    }
    return str;
}

string getpow(object me, object ob)
{
        object weapon;
        string skill_type,parry_type;
        int attack_points;
        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
                parry_type = "parry";
        }
        else
        {
                skill_type = "unarmed";
                parry_type = "unarmed";
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
//      attack_points = ob->query_skill(skill_type);
        return  power_level(attack_points);
}

int look_living(object me, object obj)
{
  object couple;
  string str, limb_status, pro, couples;
  mixed *inv;
  mapping my_fam, fam;

  if( !wizardp(me) && obj->query_temp("invis") ) return 0;
  // 隱身系統
  if( obj->query("inv") > me->query_temp("inv") )
    return 0;
  

  if( me!=obj )
    message("vision", me->name() + "正盯著你看﹐不知道打些什麼主意。\n", obj);

  if(!stringp(str=obj->query("describe")))
        str="";

  str += obj->long();

  pro = (obj==me)?gender_self(obj->query("gender")):gender_pronoun(obj->query("gender"));

  if ( (string)obj->query("race")=="人類" && intp(obj->query("age")) )
    str += sprintf("%s看起來約%s多歲。",
    pro, chinese_number(obj->query("age") / 10 * 10));

  if(obj->query("couples/id")) {
    if( couple=find_player(obj->query("couples/id"))) {
      if( couple->query("name") != obj->query("couples/name"))
        obj->set("couples/name",couple->query("name"));
    }
    else {
      if( couple=FINGER_D->acquire_login_ob(obj->query("couples/id"))) {
        if( couple->query("name") != obj->query("couples/name"))
          obj->set("couples/name",couple->query("name"));
        destruct(couple);
      }
    }
  }
  couples = obj->query("couples/name");
  if (couples) str += "配偶是"+couples;
  str += "\n";
  if ( (string)obj->query("race")=="人類" && intp(obj->query("age")) )
  str += getper(me,obj);
 
  str += sprintf("武功\看上去");
  str += getpow(me,obj);
  str += sprintf("。\n");

  // If we both has family, check if we have any relations.
  if( obj!=me &&
      mapp(fam = obj->query("family")) &&
      mapp(my_fam = me->query("family"))  &&
      fam["family_name"] == my_fam["family_name"] )
  {
    if( fam["generation"]==my_fam["generation"] ) {
      if( (string)obj->query("gender") == "男性" )
        str += sprintf( pro + "是你的%s%s。\n",
               my_fam["master_id"] == fam["master_id"] ? "": "同門",
               my_fam["enter_time"]>fam["enter_time"]? "師兄":"師弟");
      else
        str += sprintf( pro + "是你的%s%s。\n",
               my_fam["master_id"] == fam["master_id"] ? "": "同門",
               my_fam["enter_time"] > fam["enter_time"] ? "師姐": "師妹");
    }
    else if ( fam["generation"] < my_fam["generation"] ) {
      if( my_fam["master_id"] == obj->query("id") )
        str += pro + "是你的師父。\n";
      else if( my_fam["generation"] - fam["generation"] > 1 )
        str += pro + "是你的同門長輩。\n";
      else if( fam["enter_time"] < my_fam["enter_time"] )
        str += pro + "是你的師伯。\n";
      else
        str += pro + "是你的師叔。\n";
    }
    else {
      if( fam["generation"] - my_fam["generation"] > 1 )
        str += pro + "是你的同門晚輩。\n";
      else if( fam["master_id"] == me->query("id") )
        str += pro + "是你的弟子。\n";
      else
        str += pro + "是你的師姪。\n";
    }
  }

  if( obj->query("max_kee") )
    str += pro + COMBAT_D->eff_status_msg((int)obj->query("kee") * 100 / (int)obj->query("max_kee")) + "\n";

    str += "狀態：" + CON_D->con_query(obj) + "\n";

  inv = all_inventory(obj);
  if( sizeof(inv) ) {
    inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
    inv -= ({ 0 });
    if( sizeof(inv) )
      str += sprintf( obj->is_corpse() ? "%s的遺物有﹕\n%s\n" : "%s身上帶著﹕\n%s\n",
              pro, implode(inv, "\n") );
  }

  // message("vision", str, me);
  me->start_more(str);

  if( obj!=me &&
      living(obj) &&
      random((int)obj->query("bellicosity")/15) > (int)me->query_per() )
  {
    write( obj->name() + "突然轉過頭來瞪你一眼。\n");
    COMBAT_D->auto_fight(obj, me, "berserk");
  }

  return 1;
}

string inventory_look(object obj, int flag)
{
    string str;

    str = obj->short();

    if( obj->query("equipped") )
    {
        if(obj->query("skill_type"))
           str = "    " + HIC + "(手持)" + NOR + "武器 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="head")
           str = "    " + HIC + "(頭部)" + NOR + "頭戴 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="neck")
           str = "    " + HIC + "(頸部)" + NOR + "頸戴 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="cloth")
         str = "    " + HIC + "(身體)" + NOR + "身穿 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="armor")
           str = "    " + HIC + "(身著)" + NOR + "外套 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="wrists")
           str = "    " + HIC + "(手腕)" + NOR + "腕套 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="armbands")
           str = "    " + HIC + "(雙臂)" + NOR + "臂套 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="shield")
           str = "    " + HIC + "(手上)" + NOR + "手握 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="hands")
           str = "    " + HIC + "(雙掌)" + NOR + "手戴 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="finger")
           str = "    " + HIC + "(手指)" + NOR + "指戴 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="finger2")
           str = "    " + HIC + "(手指)" + NOR + "指戴 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="waist")
       str = "    " + HIC + "(腰部)" + NOR + "腰繫 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="leggings")
           str = "    " + HIC + "(雙腿)" + NOR + "腿套 " + HIC + "- "+NOR+obj->short();
        if(obj->query("armor_type")=="boots")
           str = "    " + HIC + "(足部)" + NOR + "足蹬 " + HIC + "- "+NOR+obj->short();
    if(obj->query("armor_type")=="cape")
           str = "    " + HIC + "(背披)" + NOR + "披著 " + HIC + "- "+NOR+obj->short();
    if(obj->query("armor_type")=="pants")
           str = "    " + HIC + "(腰下)" + NOR + "穿著 " + HIC + "- "+NOR+obj->short();
        }
//               str = HIC + "  - " + NOR + str;
       else
         if( !flag )
                str = "    " + str;
       else
                return 0;
        return str;
  /*
  if( obj->query("equipped") )
    str = HIC + "  ˇ" + NOR + str;
  else if( !flag )
    str = "    " + str;
  else
    return 0;

  return str;
  */
}

int look_room_item(object me, string arg)
{
  object env;
  mapping item, exits;
  string temp;


  env = environment(me);
  if ( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
    if( stringp(item[arg]) )
      write(ansi(item[arg]));
    else if( functionp(item[arg]) )
      write(ansi((string)(*item[arg])(me)));

    return 1;
  }

  if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
    if(!sscanf(exits[arg],"%s.c",temp)) exits[arg]+=".c";
    if( objectp(env = find_object(exits[arg])) )
      look_room(me, env, 1);
    else {
      if(file_size(exits[arg])>0){
      call_other(exits[arg], "???");
      look_room(me, find_object(exits[arg]), 1);
      }
    }
    return 1;
  }
  return notify_fail("你要看什麼﹖\n");
}

string power_level(int power)
{
        int lvl = 0, scale = 10;
        float factor = 1.666;
    int rawlvl;
        int grade = 1;
        if(power<0) power=0;
          power=power/5;
        while( power / scale > 1 ) {
                lvl++;
                scale = (int)(scale * factor);
                factor = factor - 0.022;
        }
         lvl=lvl;
        if( lvl >= sizeof(power_level_desc) )
                lvl = sizeof(power_level_desc)-1;
        return power_level_desc[((int)lvl)];
}

int help (object me)
{
        write(@HELP
指令格式 : look [<物品>|<生物>|<方向>]
指令說明 :
           這個指令讓你查看你所在的環境、
           某件物品、生物、或是方向。
HELP );
        return 1;
}
