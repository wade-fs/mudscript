#include <ansi.h>
mixed command = ([
  "item" : ({
    "look $id",
    "get $id",
    "get all",
    "drop $id",
    "sac $id",
    "wear $id",
    "wield $id",
    "remove $id",
    "unwield $id",
    "sell $id"
    }),
  "char" : ({
    "look $id",
    "kill $id",
    "fight $id",
    "consider $id",
    "get all from $id",
    }),
  "board" : ({
    "look $id",
    "read new",
    }),
  "skill" : ({
      "learn $arg from $id",
      }),
  "vendor" : ({
      "buy $id_string",
      "buy 10 $id_string",
      "buy 20 $id_string",

      }),
  "med" : ({
      "buy $id_string",
      "buy 10 $id_string",
      "buy 20 $id_string",
      "buy 30 $id_string",
      "buy 40 $id_string",
      }),

    ]);
string transfer(object ob, string str)
{
  object me ;
  string id ,zmud_msg,*cmd;
  string *ids ,*inherits ,id_string;
  me = this_player();
  if(!ob || !me || !me->query("env/mxp")) 
    return str;

  ids = explode(file_name(ob),"#");
  id = (sizeof(ids) > 1) ? ids[1] : ob->query("id");
  id_string = ob->query("id");
  inherits = deep_inherit_list(ob);
  //          string id = inv[i]->query("id");
  if(ob->is_character() ) 
    cmd = command["char"];
  if(member_array("/std/item.c",inherits) != -1 ) {
    if(environment(ob))
      cmd = command["item"];
    else 
      cmd = command["vendor"];
  }
  if( member_array("/std/item/combined.c",inherits) != -1) {
    if(environment(ob))
      cmd = command["item"];
    else 
      cmd = command["med"];
  }
  if(member_array("/std/bboard.c",inherits) != -1)
    cmd = command["board"];

  if(!undefinedp(cmd)) {
    string comp_cmd ="";
    zmud_msg = "[操作]";
    foreach(string c in cmd)
    {

      c = replace_string(c,"$id_string",id_string);
      c = replace_string(c,"$id",id);
      c = replace_string(c,"$arg",str);
      comp_cmd += c + "|";
    }
    comp_cmd = comp_cmd[0..<2];
    zmud_msg = str + "<send \""+comp_cmd+"\">" +  zmud_msg + "</send>";
    zmud_msg = ESC+"[6z"+ zmud_msg +ESC +"[7z";
  } else {
    zmud_msg = str;
  }
  return zmud_msg;
}
