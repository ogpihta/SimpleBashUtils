import os
import unittest

def calc(flag=""):
    os.system(f"cat {flag} test.txt > system")
    os.system(f"./s21_cat {flag} test.txt > my_cat")
    os.system(f"diff system my_cat > result")

class TestCat(unittest.TestCase):

    def test_no_flag(self):
        calc()
        self.assertEqual(os.path.getsize("result"), 0, "Error")

    def test_flag_e(self):
        calc("-e")
        self.assertEqual(os.path.getsize("result"), 0, "Error")

    def test_flag_n(self):
        calc("-n")
        self.assertEqual(os.path.getsize("result"), 0, "Error")

    def test_flag_b(self):
        calc("-b")
        self.assertEqual(os.path.getsize("result"), 0, "Error")

    def test_flag_t(self):
        calc("-t")
        self.assertEqual(os.path.getsize("result"), 0, "Error")
    
    def test_flag_s(self):
        calc("-s")
        self.assertEqual(os.path.getsize("result"), 0, "Error")

if __name__ == '__main__':
    unittest.main()
