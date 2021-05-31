
all:
	python3 setup.py build_ext --inplace

clean:
	@rm -rf __pycache__
	@rm -rf .pytest_cache
	@rm -rf build
	@rm node.cpython-*-darwin.so

test:
	@pytest