def mode(data):
    if len(data) == 0:
        mode = 0
    else:
        max_freq = 0
        for i in data:
            freq = data.count(i)
            if freq > max_freq:
                max_freq = freq
                f = data.index(i)
            mode = data[f]
        return mode


def median(obsr):
    if len(obsr) == 0:
        median = 0
    sort_obsr = sorted(obsr)
    n = len(sort_obsr)
    if n % 2 == 0:
        med = int(n/2)
        median = sort_obsr[med-1]
    else:
        med = int((n+1)/2)
        median = sort_obsr[med-1]
    return median


def mean(obsr):
    if len(obsr) == 0:
        mean = 0
    else:
        sum = 0
        for i in obsr:
            sum += int(i)
        mean = sum / len(obsr)
    return mean
