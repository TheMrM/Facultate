document.addEventListener('DOMContentLoaded', function() {
    const menuBtn = document.getElementById('menuBtn');
    const navLinks = document.getElementById('navLinks');

    menuBtn.addEventListener('click', function() {
        this.classList.toggle('open');
        navLinks.classList.toggle('show');
    });
});


document.addEventListener("DOMContentLoaded", function() {
    const slideContainer = document.querySelector('.icoane-firme');
    const images = slideContainer.querySelectorAll('img');
    const dotsContainer = document.querySelector('.carousel-dots');
    let activeIndex = 0;

    function createDots() {
        for (let i = 0; i < images.length; i++) {
            const dot = document.createElement('span');
            dot.classList.add('dot');
            dot.addEventListener('click', () => moveToSlide(i));
            dotsContainer.appendChild(dot);
        }
    }

    function moveToSlide(index) {
        const slideWidth = slideContainer.scrollWidth / images.length;
        slideContainer.scrollLeft = slideWidth * index;
        updateActiveDot(index);
        activeIndex = index;
    }

    function updateActiveDot(index) {
        const dots = dotsContainer.querySelectorAll('.dot');
        dots.forEach(dot => dot.classList.remove('active-dot'));
        dots[index].classList.add('active-dot');
    }

    document.querySelector('.fa-chevron-right').addEventListener('click', () => {
        if(activeIndex < images.length - 1) {
            moveToSlide(++activeIndex);
        } else {
            moveToSlide(0);
        }
    });

    document.querySelector('.fa-chevron-left').addEventListener('click', () => {
        if(activeIndex > 0) {
            moveToSlide(--activeIndex);
        } else {
            moveToSlide(images.length - 1);
        }
    });

    createDots();
    updateActiveDot(activeIndex);
});
