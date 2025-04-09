import logging
import sys

from pathlib import Path
from rsl_comm_py import UM7Serial

# um7 = UM7Serial(port_name='/dev/ttyAMA0')
# um7_serial.creg_com_rates2 = 10
# for packet in um7_serial.recv_all_raw_broadcast():
#     print(f"packet: {packet}")

if __name__ == '__main__':
    logging.basicConfig(
        level=logging.WARNING,
        format='[%(asctime)s.%(msecs)03d] [%(levelname)-8s]:  %(message)s',
        datefmt='%Y-%m-%d %H:%M:%S',
        handlers=[
            logging.FileHandler(f'{Path(__file__).stem}.log', mode='w'),
            logging.StreamHandler(sys.stdout),
        ])
    script_dir = Path(__file__).parent
    device_file = script_dir.parent / "rsl_A500CNP8.json"

    um7 = UM7Serial(port_name='/dev/ttyAMA0')

    print("This script lists all available commands for UM7, running these commands might erase your settings.\n"
          "Executing these commands in order does not have any meaning, all commands are listed for reference only.\n"
          "Change the code in this fine to run all the commands you need.")
    know_what_will_happen = True
    if not know_what_will_happen:
        print("NO commands will be executed, Get firmware revision and exit.\n"
              "Everything is fine, all the settings stay unchanged.\n"
              "To execute the commands change the `know_what_will_happen` to `True` and select commands you need.")
        print(f"get_fw_revision               : {um7.get_fw_revision}")
    else:
        print(f"\\n========== COMMAND REGISTERS ===================================")
        um7.reset_to_factory()
        # print(f"get_fw_revision               : {um7.get_fw_revision}")
        # print(f"flash_commit                  : {um7.flash_commit}")
        # print(f"reset_to_factory              : {um7.reset_to_factory}")
        # print(f"zero_gyros                    : {um7.zero_gyros}")
        # print(f"set_home_position             : {um7.set_home_position}")
        # print(f"set_mag_reference             : {um7.set_mag_reference}")
        # print(f"calibrate_accelerometers      : {um7.calibrate_accelerometers}")
        # print(f"reset_ekf                     : {um7.reset_ekf}")
