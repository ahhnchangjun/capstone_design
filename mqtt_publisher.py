import serial
import paho.mqtt.client as mqtt

# MQTT 브로커 설정
broker_address = 'test.mosquitto.org'  # MQTT 브로커 주소
broker_port = 1883  # MQTT 브로커 포트

# Arduino 시리얼 포트 설정
port = 'tty.usbserial-1130'  # Arduino가 연결된 포트 이름
baudrate = 9600  # 시리얼 통신 속도


def on_connect(client, userdata, flags, rc):
    print('Connected to MQTT broker')


def on_publish(client, userdata, mid):
    print('Data published')


def read_data():
    try:
        ser = serial.Serial(port, baudrate)

        # MQTT 클라이언트 초기화
        client = mqtt.Client()
        client.on_connect = on_connect
        client.on_publish = on_publish
        client.connect(broker_address, broker_port)

        while True:
            data = ser.readline().strip()  # 시리얼 포트로부터 데이터 읽기
            if data:
                # 데이터 처리
                # 예: 데이터 출력
                print("Received data:", data.decode())
                client.publish("cow1/data", data.decode())


    except serial.SerialException:
        print("Serial port connection failed.")
    except KeyboardInterrupt:
        print("Program terminated.")


if __name__ == '__main__':
    read_data()