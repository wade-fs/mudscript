// name.c

#include <ansi.h>
#include <dbase.h>

static string *my_id;

void set_name(string name, string *id)
{
        set("name", name);
        set("id", id[0]);
        my_id = id;
}

int id(string str)
{
        string *applied_id;

				if( this_player() )
				{
				   if( !this_player()->visible(this_object())  ) return 0;
					 if( this_player()->query_temp("inv") < query("inv"))
							return 0;
           if( this_player() != this_object() && 
               !wizardp(this_player()) && query_temp("invis")) 
             return 0;
				}
    
        applied_id = explode(file_name(this_object()),"#");
        if(member_array(str,applied_id) != -1)
          return 1;

        if( pointerp(applied_id = query_temp("apply/id")) 
        &&      sizeof(applied_id) ) 
                if( member_array(str, applied_id)!=-1 )
                        return 1;
                else
                        return 0;
                        
        // If apply/id exists, this object is "pretending" something, don't
        // recognize original id to prevent breaking the pretending with "id"
        // command.

        if( pointerp(my_id) && member_array(str, my_id)!=-1 )
                return 1;
        else if(this_player() && !userp(this_object())
				        && this_object()->is_character() 
				        && this_player()->query("env/sid") )
        {
            foreach( string filter in "`^$*+?\\[].()")
                str=replace_string(str, sprintf("%c",filter),"");
            if( str =="")  return 0;
            // 字頭符合的虛字串
            if( regexp(my_id, "^"+str) != ({})) return 1;

        }
        return 0;
}

string *parse_command_id_list()
{
        string *applied_id;

        if( pointerp(applied_id = query_temp("apply/id")) 
        &&      sizeof(applied_id) )
                return applied_id;
        else
                return my_id;
}

varargs string name(int raw)
{
        string str, *mask;
        
        if( !raw && sizeof(mask = query_temp("apply/name")) )
                return mask[sizeof(mask)-1];
        else {
                if( stringp(str = query("name")) )
                        return str;
                else
                        return file_name(this_object());
        }
}

varargs string short(int raw)
{
        string title, nick, str, *mask;
        int ex_def,ex_add;
        
        if( !stringp(str = query("short")) )
                str = name(raw) + "(" + capitalize(query("id")) + ")";

        if( this_object()->is_character() ){

          if( stringp(nick = query("nickname")) )
            str = sprintf("「%s」%s", nick, str);
                 
          if(query_temp("ride_name"))
            title = query_temp("ride_name");
          else 
            title = query("title");
          if( stringp(title) )
            str = sprintf("%s%s%s", title,(nick?"":" "), str);


          if( !raw ) {
                if( this_object()->is_ghost() ) str = HIB "(鬼氣) " NOR + str;
                if( this_object()->is_fighting() ) str += " " HIY+BMAG "<戰鬥中>" NOR;
                if( query_temp("netdead") ) str += HIG " <斷線中>" NOR;
                if( query_temp("shit") ) str += HIY "〈大便中〉" NOR;
                if( in_input() ) str += HIC " <輸入文字中>" NOR;
                if( in_edit() ) str += HIY " <編輯檔案中>" NOR;
                if( query("inv") ) str = HIB"(隱身中)"NOR + str;
                if( interactive(this_object())
                &&      query_idle( this_object() ) > 120 ) str += HIM " <發呆中>" NOR;
                if( !living(this_object()) ) str += HIR + query("disable_type") + NOR;
          }
        }
//add by bss,物品如果有設定某些特殊函數，會在名字後面註明 09/25/03
        else{
          str=name(raw);
          if(ex_def=this_object()->query("ex_def_power")){
            switch(ex_def){
              case 1..2:
                str+=sprintf(NOR"+%d",ex_def);
                break;
              case 3..4:
                str+=sprintf(HIG"+%d"NOR,ex_def);
                break;
              case 5..7:
                str+=sprintf(HIR"+%d"NOR,ex_def);
                break;
              case 8..10:
                str+=sprintf(HIY"+%d"NOR,ex_def);
                break;
              case 11..12:
                str+=sprintf(HBRED+HIY"+%d"NOR,ex_def);
                break;
              default:
                break;
            }
          }
          if(ex_add=this_object()->query("ex_add_def")){
            if(ex_add >=1 && ex_add <=4)
              str+=sprintf(HIC"追%d"NOR,ex_add*4);
          }
          if(this_object()->query("ex_lucky"))
            str+=HIM"幸運裝備"NOR;
          str +="(" + capitalize(query("id")) + ")";

        }    
        str=ADVANCE_ZMUD->transfer(this_object(),trans_color(str));

        return str;
}

varargs string long(int raw)
{
        string str, extra, *mask;
        
        if( !stringp(str = query("long")) )
                str = short(raw) + "。\n";

        if( stringp(extra = this_object()->extra_long()) )
                str += extra;

        return str;
}

