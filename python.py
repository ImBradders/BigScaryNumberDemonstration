import math
from datetime import datetime


def timefunc(func):
    def wrapper(*args, **kwargs):
        start_time = datetime.now()
        func(*args, **kwargs)
        end_time = datetime.now()
        running_time = end_time - start_time
        print("Ran for: ", end="")
        print(running_time.total_seconds())
    return wrapper


@timefunc
def loop_number(number):
    count = 0
    while count < number:
        print(count)
        count += 1


# This ran for 22 minutes on my system
your_number = math.factorial(12)
loop_number(your_number)