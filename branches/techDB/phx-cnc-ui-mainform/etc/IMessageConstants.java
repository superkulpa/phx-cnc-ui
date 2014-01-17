//package ru.autogenmash.core.net;

public interface IMessageConstants
{
    public static final String DELIMITER = "$";
    public static final String SIMPLE_DELIMITER = "#";
    public static final String END_OF_MESSAGE = "\n";
    public static final String MSG_STATE_PREFIX = "state_";
    public static final String MSG_CMD_PREFIX = "cmd_";

    //общие значения
    public static final String MSG_VALUE_OFF = "off";
    public static final String MSG_VALUE_ON = "on";
    public static final String MSG_VALUE_REEVENT = "reevent";
    public static final String MSG_VALUE_INVERT = "invert";
    public static final String MSG_VALUE_INC = "inc";
    public static final String MSG_VALUE_DEC = "dec";
    public static final String MSG_VALUE_ZERO = "0";
    public static final String MSG_VALUE_AUTO = "auto";
    public static final String MSG_VALUE_STOP = "stop";

////////////////////////////////////////////////////////////////////////////////
  //Общие для драйверов ввода/вывода
    public static final String MSG_SECTION_IO = "IO";

    public static final String MSG_CMD_SET_VALUE = "cmd_set_value";
//      public static final String MSG_VALUE_INVERT = "invert";
//      public static final String MSG_VALUE_INC = "inc";
//      public static final String MSG_VALUE_DEC = "dec";
//      public static final String MSG_VALUE_ZERO = "0";

    public static final String MSG_STATE_GET_VALUE = "state_value";
    public static final String MSG_STATE_RECV_VALUE = "state_recv";
////////////////////////////////////////////////////////////////////////////////
//
    public static final String MSG_SECTION_START = "start";

    public static final String MSG_CMD_SHUTDOWN = "cmd_shutdown";
    public static final String MSG_CMD_REBOOT = "cmd_reboot";
    public static final String MSG_CMD_RESTART = "cmd_restart";
    public static final String MSG_CMD_FORM_RESTART = "cmd_form_restart";
    public static final String MSG_CMD_START_UTILS = "cmd_start_utils";

////////////////////////////////////////////////////////////////////////////////
//Общие для управляющих
    public static final String MSG_SECTION_OPERATOR = "oper";
//
//    public static final String MSG_STATE_STATUS = "state_status";
//
//    public static final String MSG_STATE_INFO = "state_info";
//
//    public static final String MSG_CMD_ON = "cmd_on";
//
//    public static final String MSG_CMD_OFF = "cmd_off";
//
//    public static final String MSG_CMD_DISACTIVATE = "cmd_disactivate";
//
//    public static final String MSG_CMD_ACTIVATE = "cmd_activate";

    public static final String MSG_CMD_STOP_OPERATION = "cmd_stop_operation";

    public static final String MSG_CMD_CONTINUE_OPERATION = "cmd_continue_operation";

    public static final String MSG_CMD_CONTROL = "cmd_control";
    public static final String MSG_CMD_RUN_CP = "cmd_run_cp";
    
    public static final String MSG_CMD_MODE_BY_STEP = "cmd_mode_by_step";

    public static final String MSG_CMD_MODE_LOOP = "cmd_mode_loop";
    
    public static final String MSG_CMD_FROM_STEP = "cmd_from_step";
    public static final String MSG_CMD_GOTO_STEP = "cmd_goto_step";
    public static final String MSG_CMD_FROM_BURN = "cmd_from_burn";
    public static final String MSG_CMD_GOTO_BURN = "cmd_goto_burn";
    
    public static final String MSG_CMD_LOAD_CP = "cmd_load_cp";

    /** Ручное абсолютное перемещение. */
    public static final String MSG_CMD_HAND_ABSOLUTE_MOVING = "cmd_hand_absolute_moving";
    /** Ручное относительное перемещение. */
    public static final String MSG_CMD_HAND_COMPARATIVE_MOVING = "cmd_hand_comparative_moving";
    /** Ручное безразмерное перемещение в направлении. */
    public static final String MSG_CMD_HAND_DIR_MOVING = "cmd_hand_dir_moving";
    /** Ручное безразмерное перемещение в направлении Z. */
    public static final String MSG_CMD_HAND_DIR_MOVING_Z = "cmd_hand_dir_moving_Z";
    
    public static final String MSG_CMD_RESET_POS = "cmd_reset_pos";
    /** +1: inc, -1:dec, 0:stop?. */
    public static final String MSG_CMD_FEED = "cmd_feed";
    public static final String MSG_CMD_MODE_FEED = "cmd_mode_feed";
    
    public static final String MSG_CMD_MOVE_AXIS = "cmd_move_axis";
    public static final String MSG_CMD_MOVE_AXIS0F = "0=+1";
    public static final String MSG_CMD_MOVE_AXIS0B = "0=-1";
    public static final String MSG_CMD_MOVE_AXIS0S = "0=0";
    public static final String MSG_CMD_MOVE_AXIS1F = "1=+1";
    public static final String MSG_CMD_MOVE_AXIS1B = "1=-1";
    public static final String MSG_CMD_MOVE_AXIS1S = "1=0";
    public static final String MSG_CMD_MOVE_AXIS2F = "2=+1";
    public static final String MSG_CMD_MOVE_AXIS2B = "2=-1";
    public static final String MSG_CMD_MOVE_AXIS2S = "2=0";
    public static final String MSG_CMD_MOVE_AXIS3F = "3=+1";
    public static final String MSG_CMD_MOVE_AXIS3B = "3=-1";
    public static final String MSG_CMD_MOVE_AXIS3S = "3=0";
    public static final String MSG_CMD_MOVE_AXIS4F = "4=+1";
    public static final String MSG_CMD_MOVE_AXIS4B = "4=-1";
    public static final String MSG_CMD_MOVE_AXIS4S = "4=0";
    public static final String MSG_CMD_MOVE_STOP = "cmd_move_stop";
	//TODO: TM. переименовать в ready
    public static final String MSG_CMD_ACTIVATE = "cmd_activate";
    public static final String MSG_CMD_DISACTIVATE = "cmd_disactivate";
    public static final String MSG_CMD_BURN = "cmd_burn";
    public static final String MSG_CMD_R_BURN = "cmd_r_burn";
    public static final String MSG_CMD_F_BURN = "cmd_tech23";
    public static final String MSG_CMD_FIRE = "cmd_fire";
    public static final String MSG_CMD_CUT2_OFF = "cmd_tech2off";

    //Управление ожидания
    public static final String MSG_CMD_WAITING   = "cmd_waiting";
    public static final String MSG_CMD_WAITING_CONTINUE = "cmd_waiting_continue";
    public static final String MSG_CMD_WAITING_BREAK = "cmd_waiting_break";

    public static final String MSG_CMD_TECHNOLOGY  = "cmd_technology";

    //Управление режимом TM
    public static final String MSG_CMD_MODE_CUT = "cmd_mode_cut";
    public static final String MSG_CMD_MODE_SVR = "cmd_mode_svr";
    public static final String MSG_CMD_SVR = "cmd_svr";

//    public static final String MSG_VALUE_SUPPORT_ALARM = "value_support_Z_stop";
    //Команды технологии
    public static final String MSG_CMD_TECH  = "cmd_tech"; //команда технологии
    public static final String MSG_CMD_TECH0  = MSG_CMD_TECH+"0"; //поиск листа
    public static final String MSG_CMD_TECH1  = MSG_CMD_TECH+"1";//поджиг
    public static final String MSG_CMD_TECH21 = MSG_CMD_TECH+"21"; //пробивка
    public static final String MSG_CMD_TECH22 = MSG_CMD_TECH+"22"; //поджиг
    public static final String MSG_CMD_TECH23 = MSG_CMD_TECH+"23"; //пробивка
    public static final String MSG_CMD_TECH24 = MSG_CMD_TECH+"24"; //пробивка
    public static final String MSG_CMD_TECH25 = MSG_CMD_TECH+"25"; //пробивка
    public static final String MSG_CMD_TECH21Off = MSG_CMD_TECH+"21Off"; //выкл реза
    public static final String MSG_CMD_TECH22Off = MSG_CMD_TECH+"22Off"; //
    public static final String MSG_CMD_TECH23Off = MSG_CMD_TECH+"23Off"; //выкл реза с ходу

    public static final String MSG_CMD_TECH_Z_STOP = MSG_CMD_TECH+"Z_stop"; //
    public static final String MSG_CMD_TECH_Z_AUTO = MSG_CMD_TECH+"Z_auto"; //
    public static final String MSG_CMD_TECH_Z_PARK = MSG_CMD_TECH+"Z_park"; //
    public static final String MSG_CMD_TECH_Z_UP = MSG_CMD_TECH+"_Z_up"; //
    public static final String MSG_CMD_TECH_Z_UP_CORRECT = MSG_CMD_TECH+"_Z_up_correct"; //
    public static final String MSG_CMD_TECH_Z_DOWN = MSG_CMD_TECH+"_Z_down"; //
    public static final String MSG_CMD_TECH_Z_DOWN_CORRECT = MSG_CMD_TECH+"_Z_down_correct"; //

    public static final String MSG_CMD_MARKER = "cmd_marker";
    
    /////////////////////////////////////////////////////////////////////////////
    public static final String MSG_SECTION_PARAMS = "section_params";
//    public static final String MSG_CMD_SET_PARAMS = "cmd_set_params";
    public static final String MSG_STATE_RELOAD_PARAMS = "state_reload_params";
    public static final String MSG_CMD_RELOAD_PARAMS = "cmd_reload_params";

    //public static final String MSG_CMD_RELOAD_INI = "cmd_reload_ini";
    
    ////////////////////////////////////////////////////////////////////////////////
  //Общие информативные сообщения
    public static final String MSG_SECTION_ALARM = "alarm";

    public static final String MSG_STATE_MULTI_ALARM = "state_multi_alarm";
    public static final String MSG_STATE_MULTI_ALARM_ADD
                                  = "state_multi_alarm_add";
    public static final String MSG_STATE_MULTI_ALARM_REMOVE
                                  = "state_multi_alarm_remove";

    public static final String MSG_STATE_INFO_ALARM = "state_info_alarm";

    public static final String MSG_STATE_RESET_ALARMS = "state_reset_alarms";

    public static final String MSG_CMD_RESET_ALARMS = "cmd_reset_alarms";

    public static final String MSG_STATE_INFO = "state_info";
    public static final String MSG_STATE_STATUS = "state_status";
    
    public static final String MSG_CMD_RED_BUTTON = "red_button";
////////////////////////////////////////////////////////////////////////////////
//
;    public static final String MSG_SECTION_CONTROL = "control";

    public static final String MSG_STATE_CONTROL = "state_control";

    public static final String MSG_STATE_RUN_CP = "state_run_cp";
    //0: stop(hand), 1: forward, 2: backward, 3: findTrj
    public static final String MSG_VALUE_HAND = "hand";
    public static final String MSG_VALUE_FORWARD = "forward";
    public static final String MSG_VALUE_BACKWARD = "backward";
    public static final String MSG_VALUE_FIND_TRJ = "find_trj";

    public static final String MSG_STATE_CP_LINE = "state_CPLine";
    
    public static final String MSG_STATE_MODE_BY_STEP = "state_by_step";
    public static final String MSG_STATE_MODE_LOOP = "state_loop";

    
//////////////////////////////////////////////////////////////////////////////////
//
    public static final String MSG_SECTION_CART = "section_cart";
    public static final String MSG_STATE_CART = "state_cart";
    public static final String MSG_CMD_CART = "cmd_cart";
//    public static final String MSG_SECTION_UTILITY = "utility";
//
//
//////////////////////////////////////////////////////////////////////////////////
//
//    /** Готовность к отработке УП. */
//    //public static final String MSG_STATE_CP_READY = "state_cp_ready";
//    public static final String MSG_CMD_DEBUG_ON_OFF = "cmd_debug_on_off";
//
//
    public static final String MSG_SECTION_MOVE = "MM";

    /** 0: normal, 0x1: fast, 0x2: low. */
    public static final String MSG_STATE_MODE_FEED = "state_mode_feed";
    public static final String MSG_VALUE_NORMAL = "0";
    public static final String MSG_VALUE_FAST = "1";
    public static final String MSG_VALUE_SLOW = "2";

    public static final String MSG_STATE_FEED_RESULT = "state_feed_result";
    public static final String MSG_STATE_FEED_PERCENTAGE = "state_feed_percentage";

    public static final String MSG_STATE_POS_AXIS = "pos_axis";
    public static final String MSG_STATE_POS_AXIS0 = "0";
    public static final String MSG_STATE_POS_AXIS1 = "1";
    public static final String MSG_STATE_POS_AXIS2 = "2";
    public static final String MSG_STATE_POS_AXIS3 = "3";
    public static final String MSG_STATE_POS_AXIS4 = "4";
    public static final String MSG_STATE_POS_AXIS5 = "5";
    

    /////////////////////////////////////////////////////////////////////////////////////
    //
    //секция "управление технологией реза"
    public static final String MSG_SECTION_TECH = "TM";
    // Номер пробивки.
    public static final String MSG_STATE_CURRENT_BURN = "state_current_burn";
    // Количество пробивок.
    public static final String MSG_STATE_COUNT_BURN = "state_count_burn";
    //Состояние ожидания выполнения техн операции
    public static final String MSG_STATE_WAITING = "state_waiting";//состояние ожидания
    //проценты progress bar, 0%-начало, 100% - конец ожидания
    // Технология, значение: тек технология(плазма, микроплазма, кислород, разметка, сверление).
    public static final String MSG_STATE_TECHNOLOGY = "state_technology";

    // Состояние суппорта, значение: состояние суппорта текущей группы(in hex)
    public static final String MSG_STATE_TECH = "state_tech"; //состояние технологии
    public static final String MSG_STATE_TECH_OFF = MSG_STATE_TECH + "_off";
    public static final String MSG_STATE_TECH_ACTIVE = MSG_STATE_TECH + "_active";
    public static final String MSG_STATE_TECH_DISACTIVE = MSG_STATE_TECH + "_disactive";
    public static final String MSG_STATE_TECH_FIRE = MSG_STATE_TECH + "_fire";
    public static final String MSG_STATE_TECH_CUT = MSG_STATE_TECH + "_cut";
    public static final String MSG_STATE_TECH_PARK = MSG_STATE_TECH + "_park"; // ищу ноль;
    public static final String MSG_STATE_TECH_FIND_SHEET = MSG_STATE_TECH + "_find_sheet"; // ищу лист;

    /** Напряжение, в десятых долях вольта.
     * Формат TM#state_svr_voltage#2=123$ или TM#state_svr_voltage#3=456$. */
    public static final String MSG_STATE_SVR_VOLTAGE = "state_svr_voltage"; //
    
    public static final String MSG_STATE_MODE_CUT  = "state_cut";
    public static final String MSG_STATE_MODE_MARKER  = "state_marker";
    public static final String MSG_STATE_MODE_SVR  = "state_svr";

    public static final String MSG_STATE_MARKER = "state_marker";

  
    //секция "управление газ. консоль"
    public static final String MSG_SECTION_GC = "GC";
    public static final String MSG_CMD_GC_RELOAD = "cmd_gc_reload"; //перегрузить давления    //секция "управление газ. консоль"
    
    public static final String MSG_CMD_GC_KM  = "cmd_gc_KM";
    public static final String MSG_CMD_GC_KP  = "cmd_gc_KP";
    public static final String MSG_CMD_GC_KPV = "cmd_gc_KPV";
    public static final String MSG_CMD_GC_KR  = "cmd_gc_KR";
    public static final String MSG_CMD_GC_KRV = "cmd_gc_KRV";
    public static final String MSG_CMD_GC_GG  = "cmd_gc_GG";
    public static final String MSG_CMD_GC_GGV = "cmd_gc_GGV";
    
    //1=123,2=234,3=456,4=678
    public static final String MSG_CMD_GC_KP1 = "cmd_gc_KP1";
    public static final String MSG_CMD_GC_KR1 = "cmd_gc_KR1";
    public static final String MSG_CMD_GC_GG1 = "cmd_gc_GG1";

    public static final String MSG_CMD_GC_KP2 = "cmd_gc_KP2";
    public static final String MSG_CMD_GC_KR2 = "cmd_gc_KR2";
    public static final String MSG_CMD_GC_GG2 = "cmd_gc_GG2";

    public static final String MSG_CMD_GC_KP3 = "cmd_gc_KP3";
    public static final String MSG_CMD_GC_KR3 = "cmd_gc_KR3";
    public static final String MSG_CMD_GC_GG3 = "cmd_gc_GG3";

    public static final String MSG_CMD_GC_KP4 = "cmd_gc_KP4";
    public static final String MSG_CMD_GC_KR4 = "cmd_gc_KR4";
    public static final String MSG_CMD_GC_GG4 = "cmd_gc_GG4";
}
